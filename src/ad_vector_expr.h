#ifndef __AD_VECTOR_EXPR_H_
#define __AD_VECTOR_EXPR_H_

template <typename LExpr,typename BinOp,typename RExpr>
class ad_vector_expr{
   public:

      ad_vector_expr(LExpr l, RExpr r) : 
         _lhs(std::forward<LExpr>(l)), 
         _rhs(std::forward<RExpr>(r)){}

      //shut down default ctor...
      ad_vector_expr() = delete;
      //...and no copies...
      ad_vector_expr(ad_vector_expr const&) = delete;
      ad_vector_expr& operator =(ad_vector_expr const&) = delete;

      // Moves are ok.
      ad_vector_expr(ad_vector_expr&&) = default;
      ad_vector_expr& operator =(ad_vector_expr&&) = default;

      /*****************************************************************************************
       *
       *   Arithmetics
       *
       ****************************************************************************************/
      template <typename RE>
         auto operator +(RE&& rhs) const ->
         ad_vector_expr<const ad_vector_expr<LExpr,BinOp,RExpr>&, 
         BinOp, decltype(std::forward<RE>(rhs))>{
            return ad_vector_expr<const ad_vector_expr<LExpr,BinOp,RExpr>&, BinOp,
            decltype(std::forward<RE>(rhs))>(*this, std::forward<RE>(rhs));
         }


      auto le() -> 
         typename std::add_lvalue_reference<LExpr>::type{ 
            return _lhs; 
         }

      auto le() const ->
         typename std::add_lvalue_reference<typename std::add_const<LExpr>::type>::type{ 
            return _lhs;
         }

      auto re() -> typename std::add_lvalue_reference<RExpr>::type {
         return _rhs;
      }

      auto re() const -> typename std::add_lvalue_reference<typename std::add_const<RExpr>::type>::type{ 
         return _rhs;
      }

      auto operator [](std::size_t index) const -> decltype(BinOp::apply(this->le()[index], this->re()[index])){
         return BinOp::apply(le()[index], re()[index]);
      }

   protected:
      LExpr _lhs;
      RExpr _rhs;
};

template <typename BinOp,typename RExpr>
class ad_vector_expr<double&&, BinOp,RExpr>{
   public:

      ad_vector_expr(double l, RExpr r) : 
         _lhs(std::forward<double>(l)), 
         _rhs(std::forward<RExpr>(r)){}

      //shut down default ctor...
      ad_vector_expr() = delete;
      //...and no copies...
      ad_vector_expr(ad_vector_expr const&) = delete;
      ad_vector_expr& operator =(ad_vector_expr const&) = delete;

      // Moves are ok.
      ad_vector_expr(ad_vector_expr&&) = default;
      ad_vector_expr& operator =(ad_vector_expr&&) = default;

      /*****************************************************************************************
       *
       *   Arithmetics
       *
       ****************************************************************************************/
      template <typename RE>
         auto operator +(RE&& rhs) const ->
         ad_vector_expr<const ad_vector_expr<double,BinOp,RExpr>&, 
         BinOp, decltype(std::forward<RE>(rhs))>{
            return ad_vector_expr<const ad_vector_expr<double,BinOp,RExpr>&, BinOp,
            decltype(std::forward<RE>(rhs))>(*this, std::forward<RE>(rhs));
         }


      auto le() -> 
         typename std::add_lvalue_reference<double>::type{ 
            return _lhs; 
         }

      auto le() const ->
         typename std::add_lvalue_reference<typename std::add_const<double>::type>::type{ 
            return _lhs;
         }

      auto re() -> typename std::add_lvalue_reference<RExpr>::type {
         return _rhs;
      }

      auto re() const -> typename std::add_lvalue_reference<typename std::add_const<RExpr>::type>::type{ 
         return _rhs;
      }

      auto operator [](std::size_t index) const -> decltype(BinOp::apply(this->le(), this->re()[index])){
         return BinOp::apply(le(), re()[index]);
      }

   protected:
      double _lhs;
      RExpr _rhs;
};

template <typename LExpr,typename BinOp>
class ad_vector_expr<LExpr,BinOp,double&&>{
   public:

      ad_vector_expr(LExpr l, double r) : 
         _lhs(std::forward<LExpr>(l)), 
         _rhs(std::forward<double>(r)){}

      //shut down default ctor...
      ad_vector_expr() = delete;
      //...and no copies...
      ad_vector_expr(ad_vector_expr const&) = delete;
      ad_vector_expr& operator =(ad_vector_expr const&) = delete;

      // Moves are ok.
      ad_vector_expr(ad_vector_expr&&) = default;
      ad_vector_expr& operator =(ad_vector_expr&&) = default;

      /*****************************************************************************************
       *
       *   Arithmetics
       *
       ****************************************************************************************/
      template <typename RE>
         auto operator +(RE&& rhs) const ->
         ad_vector_expr<const ad_vector_expr<LExpr,BinOp,double>&, 
         BinOp, decltype(std::forward<RE>(rhs))>{
            return ad_vector_expr<const ad_vector_expr<LExpr,BinOp,double>&, BinOp,
            decltype(std::forward<RE>(rhs))>(*this, std::forward<RE>(rhs));
         }

      auto le() -> 
         typename std::add_lvalue_reference<LExpr>::type{ 
            return _lhs; 
         }

      auto le() const ->
         typename std::add_lvalue_reference<typename std::add_const<LExpr>::type>::type{ 
            return _lhs;
         }

      auto re() -> typename std::add_lvalue_reference<double>::type {
         return _rhs;
      }

      auto re() const -> typename std::add_lvalue_reference<typename std::add_const<double>::type>::type{ 
         return _rhs;
      }

      auto operator [](std::size_t index) const -> decltype(BinOp::apply(this->le()[index], this->re())){
         return BinOp::apply(le()[index], re());
      }

   protected:
      LExpr _lhs;
      double _rhs;
};


#endif
