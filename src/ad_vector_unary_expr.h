#ifndef __AD_VECTOR_UNARY_EXPR_H_
#define __AD_VECTOR_UNARY_EXPR_H_

template <typename InExpr, typename UnaryOp>
class ad_vector_unary_expr{
   public:

      ad_vector_unary_expr(InExpr l) : 
         _lhs(std::forward<InExpr>(l)){}

      //shut down default ctor...
      ad_vector_unary_expr() = delete;
      //...and no copies...
      ad_vector_unary_expr(ad_vector_unary_expr const&) = delete;
      ad_vector_unary_expr& operator =(ad_vector_unary_expr const&) = delete;

      // Moves are ok.
      ad_vector_unary_expr(ad_vector_unary_expr&&) = default;
      ad_vector_unary_expr& operator =(ad_vector_unary_expr&&) = default;

      /*****************************************************************************************
       *
       *   Arithmetics
       *
       ****************************************************************************************/
      template <typename RE>
      auto operator +(RE&& rhs) const ->
      ad_vector_unary_expr<const ad_vector_unary_expr<InExpr,UnaryOp>&, 
      unaryOp, decltype(std::forward<RE>(rhs))>{
         return ad_vector_unary_expr<const ad_vector_unary_expr<InExpr,UnaryOp>&, unaryOp,
         decltype(std::forward<RE>(rhs))>(*this, std::forward<RE>(rhs));
      }

      auto input() -> 
      typename std::add_lvalue_reference<InExpr>::type{ 
         return _in; 
      }

      auto input() const ->
      typename std::add_lvalue_reference<typename std::add_const<InExpr>::type>::type{ 
         return _in;
      }

      auto operator [](std::size_t index) const -> decltype(UnaryOp::apply(this->input()[index])){
         return unaryOp::apply(input()[index]);
      }

   protected:
      InExpr _in;
};

#endif
