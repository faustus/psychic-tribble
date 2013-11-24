#ifndef __ADTYPE_H_
#define __ADTYPE_H_

#include <array>
#include <initializer_list>
#include <type_traits>

#include "ad_operator_templates.h"

template<class T=double, std::size_t N=1>
class ADType{
   public:
      //ctors
      ADType():
         _n(N),
         _val((T)0){
            std::fill(begin(_deriv), end(_deriv), std::array<T,N>{});
      }

      ADType(T val):
         _n(N),
         _val((T)0){
            std::fill(begin(_deriv), end(_deriv), std::array<T,N>{});
      }

      ADType(const ADType& in):
         _n(N),
         _val(in._val){
            std::copy(begin(in._deriv), end(in._deriv), begin(_deriv));
      }

      ADType(ADType&& in):
         _n(N),
         _val(in._val){
            std::move(begin(in._deriv), end(in._deriv), begin(_deriv));
      }

      ADType& operator=(const ADType& in){
         std::copy(begin(in._deriv), end(in._deriv), begin(_deriv));
         _val = _in.val;
      }

      ADType& operator=(ADType&& in){
         std::move(begin(in._deriv), end(in._deriv), begin(_deriv));
         _val = in._val;
      }
      //no dctor, compiler will handle
      
      //Accessor
      T value() { return _val; }
      T deriv(std::size_t i) { return _deriv[i]; }

      //mutator
      void set_value(T val) { _val = val; }
      void set_deriv(T val) {
         std::fill(begin(_deriv), end(_deriv), val);
      }

      //random methods
      //swap is always useful
      void swap(ADType& in){
         std::swap(_deriv,in._deriv);
         _val = in._val;
      }
      
      ADType& operator+=(T val){
         _val += val;
         return *this;
      }

      ADType& operator+=(const ADType& in){
         for(std::size_t i=0; i < N; ++i)
            _deriv[i] += in._deriv[i];
         _val += in._val;
      }
      ADType& operator+=(ADType&& in);

      //signatures for other ops
   private:
      T _val;
      std::array<T,N> _deriv;
};

#endif

