#ifndef __ADVECTOR_POW_DEFN_H_
#define __ADVECTOR_POW_DEFN_H_

#include <cmath>
#include "ad_vector_bin_expr.h"
template<typename T, typename Expr>
class ad_vector_pow{
   public:

      ad_vector_pow(Expr e, T ex):
         _expr(std::forward<Expr>(e)),
         _exp(std::forward<T>(ex)){}

      ad_vector_pow(Expr& e, T& ex):
         _expr(std::forward<Expr>(e)),
         _exp(std::forward<T>(ex)){}

      //shut down default ctor...
      ad_vector_pow() = delete;
      //no copying neither
      ad_vector_pow(ad_vector_pow const&) = delete;
      ad_vector_pow& operator=(ad_vector_pow const&) = delete;
      //moves are ok tho
      ad_vector_pow(ad_vector_pow &&) = default;
      ad_vector_pow& operator=(ad_vector_pow &&) = default;
      
      T operator[](std::size_t i) const{
         return std::pow(_expr[i],_exp);
      }
      
   private:
      Expr _expr;
      T _exp;
};
#endif
