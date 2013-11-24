#ifndef __BIN_EXPR_INTERP_H_
#define __BIN_EXPR_INTERP_H_
/******************************************************************************
 *
 *    Interpretrer for Binary Operations using expression templates
 *
 *    rev 0.0.1 23Nov2013
 *    wes cothran
 *
 *****************************************************************************/
#include <array>
#include <utility>

#include "adtype.h"
//TODO: templetize once working
//Define base classes

//Literal datatype for POD types
template <class T=double, int N=1>
class Literal{
   public:
      Literal(const T x): _val(x){}
      Literal(T&& x): _val(x){
         x = 0.;
      }

      T value() const { return this->_val; }
      T deriv() const { return (T)(0.); }
   private:
      const T _val;
};

//Variable Type. 
//Booooring now, add more interesting things later
template <class T=double, int N=1>
class Variable{
   public:
      Variable(T& x) : _val(x){}
      
      T value() const { return this->_val; }
      T deriv(int i) const { return this->_deriv[i]; }
   private:
      T& _val;
      std::array<T,N> _deriv;
};

template<class ExprT> struct exprTrait{
   typedef ExprT expr_type;
};

template<> struct exprTrait<double>{
   typedef Literal<double> expr_type;
};

template<> struct exprTrait<int>{
   typedef Literal<int> expr_type;
};

template<> struct exprTrait<long>{
   typedef Literal<long> expr_type;
};

//Binary Expression Operation evaluation
template <class ExprT, class ExprU, class BinOp>
class BinaryExpr{
   public:
      BinaryExpr(ExprT lhs, ExprU rhs, BinOp op=BinOp()):
         _expr_lhs(lhs),
         _expr_rhs(rhs),
         _op(op){}
      auto value()->decltype(_op(_expr_lhs.value(), _expr_rhs.value())) const{
         return _op(_expr_lhs.value(), _expr_rhs.value());
      }
   private:
      typename exprTrait<ExprT>::expr_type _expr_lhs;
      typename exprTrait<ExprU>::expr_type _expr_rhs;
      BinOp _op;
};

template <class ExprT>
auto value(ExprT e)->decltype(e.value()) { return e.value(); }
#endif
