#ifndef __AD_VECTOR_BASE_H_
#define __AD_VECTOR_BASE_H_

template <class T, std::size_t N> class ad_vector;

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

//===========================================================================

template <typename T>
struct plus_op{
   static T apply(const T& a, const T& b){
      return a + b;
   }

   static T apply(T&& a, const T& b){
      a += b;
      return std::move(a);
   }

   static T apply(const T& a, T&& b){
      b += a;
      return std::move(b);
   }

   static T apply(T&& a, T&& b){
      a += b;
      return std::move(a);
   }
};

//===========================================================================

template <class T=double, std::size_t N=1>
class ad_vector{

   public:
      ad_vector(){
         std::fill(begin(_val), end(_val), std::array<T,N>{});
         std::cout << this << ": ad_vector()" << std::endl;
      }

      ad_vector(const ad_vector& in) noexcept{
         std::copy(begin(in._val), end(in._val), begin(_val));
         std::cout << this << ": ad_vector(copy: " << &in << ")" << std::endl;
      }

      ad_vector(ad_vector&& in) noexcept {
         std::move(begin(in._val), end(in._val), begin(_val));
         std::cout << this << ": ad_vector(move: " << &in << ")" << std::endl;
      }

      ad_vector(std::initializer_list<typename std::array<T,N>::value_type> l) {
         std::copy(begin(l), end(l), begin(_val));
         std::cout << this << ": ad_vector(initlist)" << std::endl;
      }

      ad_vector& operator =(const ad_vector& in) noexcept {
         std::copy(begin(in._val), end(in._val), begin(_val));
         std::cout << this << ": ad_vector op =(copy: " << &in << ")" << std::endl;
         return *this;
      }

      ad_vector& operator =(ad_vector&& in) noexcept {
         std::move(begin(in._val), end(in._val), begin(_val));
         std::cout << this << ": ad_vector op =(move: " << &in << ")" << std::endl;
         return *this;
      }

      ~ad_vector() {
         std::cout << this << ": ~ad_vector()" << std::endl;
      }

      void swap(ad_vector& in) {
         for (std::size_t i = 0; i<N; ++i)
            std::swap(_val[i], in[i]);
      }

      auto operator [](std::size_t index) const -> typename std::array<T,N>::value_type const& {
            return _val[index];
      }

      auto operator [](std::size_t index) -> typename std::array<T,N>::value_type& {
            return _val[index];
      }

      ad_vector& operator +=(const ad_vector& b) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] += b[i];
         return *this;
      }

      template <typename LE, typename Op, typename RE>
      ad_vector(ad_vector_expr<LE,Op,RE>&& expr) {
        for (std::size_t i = 0; i < N; ++i)
               _val[i] = expr[i];
         std::cout << this << ": ad_vector(expr: " << &expr << ")" << std::endl;
      }

      template <typename RightExpr>
      ad_vector& operator =(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] = rhs[i];
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator +=(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] += rhs[i];
         return *this;
      }

      template <typename RightExpr>
      auto operator +(RightExpr&& rhs) const ->ad_vector_expr<const ad_vector&, 
                                                              plus_op<typename std::array<T,N>::value_type>,
                                                              decltype(std::forward<RightExpr>(rhs))> {
         return ad_vector_expr<const ad_vector&, 
                               plus_op<typename std::array<T,N>::value_type>, 
                               decltype(std::forward<RightExpr>(rhs))>(*this, std::forward<RightExpr>(rhs));
      }

   private:
      std::array<T,N> _val;
};

//===========================================================================

template <class T, std::size_t N>
inline void swap(ad_vector<T,N>& a, ad_vector<T,N>& b){
   a.swap(b);
}

//===========================================================================


   template <class T, std::size_t N>
std::ostream& operator <<(std::ostream& os, const ad_vector<T,N>& mv){
   os << '(';
   for (std::size_t i = 0; i < N; ++i)
      os << mv[i] << ((i+1 != N) ? ',' : ')');
   return os;
}

//===========================================================================

#endif
