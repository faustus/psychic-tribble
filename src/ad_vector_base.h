#ifndef __AD_VECTOR_BASE_H_
#define __AD_VECTOR_BASE_H_

#include <array>
#include <algorithm>
#include <initializer_list>
#include <type_traits>
#include <iostream>

#include "ad_vector_bin_expr.h"
#include "generic_op_structs.h"

template <class T=double, std::size_t N=1>
class ad_vector{

   public:
      /////////////////////////////////////////////////////////////////////////
      /************************************************************************
       * CTORS, DCTORS, ASSIGNS
       ***********************************************************************/
      /////////////////////////////////////////////////////////////////////////
      
      /************************************************************************
       * CTORS
       ***********************************************************************/
      ad_vector(){
         std::fill(std::begin(_val), std::end(_val), (T)0.);
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector()" << std::endl;
         #endif
      }

      ad_vector(const ad_vector& in) noexcept{
         std::copy(std::begin(in._val), std::end(in._val), std::begin(_val));
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector(copy: " << &in << ")" << std::endl;
         #endif
      }

      ad_vector(ad_vector&& in) noexcept {
         std::move(std::begin(in._val), std::end(in._val), std::begin(_val));
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector(move: " << &in << ")" << std::endl;
         #endif
      }

      ad_vector(std::initializer_list<typename std::array<T,N>::value_type> l) {
         std::copy(std::begin(l), std::end(l), std::begin(_val));
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector(initlist)" << std::endl;
         #endif
      }

      template <typename LE, typename Op, typename RE>
      ad_vector(ad_vector_bin_expr<LE,Op,RE>&& expr) {
        for (std::size_t i = 0; i < N; ++i)
               _val[i] = expr[i];
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector(expr: " << &expr << ")" << std::endl;
         #endif
      }

      /************************************************************************
       * ASSIGNS
       ***********************************************************************/
      ad_vector& operator =(const ad_vector& in) noexcept {
         std::copy(std::begin(in._val), std::end(in._val), std::begin(_val));
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector op =(copy: " << &in << ")" << std::endl;
         #endif
         return *this;
      }

      ad_vector& operator =(ad_vector&& in) noexcept {
         std::move(std::begin(in._val), std::end(in._val), std::begin(_val));
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector op =(move: " << &in << ")" << std::endl;
         #endif
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator =(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] = rhs[i];
         #ifdef _VERBOSE
         std::cout << this << ": ad_vector op =(expr: " << &rhs << ")" << std::endl;
         #endif
         return *this;
      }

      /************************************************************************
       * DCTOR
       ***********************************************************************/
      ~ad_vector() {
         #ifdef _VERBOSE
         std::cout << this << ": ~ad_vector()" << std::endl;
         #endif
      }

      /////////////////////////////////////////////////////////////////////////
      /************************************************************************
       * UTILITY
       ***********************************************************************/
      /////////////////////////////////////////////////////////////////////////
      typedef T value_type;
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

      /////////////////////////////////////////////////////////////////////////
      /************************************************************************
       * ARITHMETIC
       ***********************************************************************/
      /////////////////////////////////////////////////////////////////////////

      /************************************************************************
       * ADDITION
       ***********************************************************************/
      ad_vector& operator +=(const ad_vector& b) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] += b[i];
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator +=(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] += rhs[i];
         return *this;
      }

      template <typename RightExpr>
      auto operator +(RightExpr&& rhs) const ->ad_vector_bin_expr<const ad_vector&, 
                                                              add_op<typename std::array<T,N>::value_type>,
                                                              decltype(std::forward<RightExpr>(rhs))> {
         return ad_vector_bin_expr<const ad_vector&, 
                               add_op<typename std::array<T,N>::value_type>, 
                               decltype(std::forward<RightExpr>(rhs))>(*this, std::forward<RightExpr>(rhs));
      }

      /************************************************************************
       * SUBTRACTION
       ***********************************************************************/
      ad_vector& operator -=(const ad_vector& b) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] -= b[i];
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator -=(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] -= rhs[i];
         return *this;
      }

      template <typename RightExpr>
      auto operator -(RightExpr&& rhs) const ->ad_vector_bin_expr<const ad_vector&, 
                                                              sub_op<typename std::array<T,N>::value_type>,
                                                              decltype(std::forward<RightExpr>(rhs))> {
         return ad_vector_bin_expr<const ad_vector&, 
                               sub_op<typename std::array<T,N>::value_type>, 
                               decltype(std::forward<RightExpr>(rhs))>(*this, std::forward<RightExpr>(rhs));
      }

      /************************************************************************
       * MULTIPLICATION
       ***********************************************************************/
      ad_vector& operator *=(const ad_vector& b) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] *= b[i];
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator *=(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] *= rhs[i];
         return *this;
      }

      template <typename RightExpr>
      auto operator *(RightExpr&& rhs) const ->ad_vector_bin_expr<const ad_vector&, 
                                                              mul_op<typename std::array<T,N>::value_type>,
                                                              decltype(std::forward<RightExpr>(rhs))> {
         return ad_vector_bin_expr<const ad_vector&, 
                               mul_op<typename std::array<T,N>::value_type>, 
                               decltype(std::forward<RightExpr>(rhs))>(*this, std::forward<RightExpr>(rhs));
      }

      /************************************************************************
       * DIVISION 
       ***********************************************************************/
      ad_vector& operator /=(const ad_vector& b) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] /= b[i];
         return *this;
      }

      template <typename RightExpr>
      ad_vector& operator /=(RightExpr&& rhs) {
         for (std::size_t i = 0; i<N; ++i)
            _val[i] /= rhs[i];
         return *this;
      }

      template <typename RightExpr>
      auto operator /(RightExpr&& rhs) const ->ad_vector_bin_expr<const ad_vector&, 
                                                              div_op<typename std::array<T,N>::value_type>,
                                                              decltype(std::forward<RightExpr>(rhs))> {
         return ad_vector_bin_expr<const ad_vector&, 
                               div_op<typename std::array<T,N>::value_type>, 
                               decltype(std::forward<RightExpr>(rhs))>(*this, std::forward<RightExpr>(rhs));
      }

   private:
      std::array<T,N> _val;
};

/////////////////////////////////////////////////////////////////////////
/************************************************************************
 * ARITHMETIC NON-CLASS
 ***********************************************************************/
/////////////////////////////////////////////////////////////////////////

/************************************************************************
 * ADDITION
 ***********************************************************************/
template <typename T, std::size_t N>
auto operator+(T&& lhs, ad_vector<T,N>&& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      add_op<typename std::array<T,N>::value_type>,
                                                      ad_vector<T,N>&&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      add_op<typename std::array<T,N>::value_type>,
                      ad_vector<T,N>&&>(std::forward<T>(lhs), rhs);
}

template <typename T, std::size_t N>
auto operator+(T&& lhs, const ad_vector<T,N>& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      add_op<typename std::array<T,N>::value_type>,
                                                      const ad_vector<T,N>&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      add_op<typename std::array<T,N>::value_type>,
                      const ad_vector<T,N>&>(std::forward<T>(lhs), rhs);
}

/************************************************************************
 * SUBTRACTION
 ***********************************************************************/
template <typename T, std::size_t N>
auto operator-(T&& lhs, ad_vector<T,N>&& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      sub_op<typename std::array<T,N>::value_type>,
                                                      ad_vector<T,N>&&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      sub_op<typename std::array<T,N>::value_type>,
                      ad_vector<T,N>&&>(std::forward<T>(lhs), rhs);
}

template <typename T, std::size_t N>
auto operator-(T&& lhs, const ad_vector<T,N>& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      sub_op<typename std::array<T,N>::value_type>,
                                                      const ad_vector<T,N>&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      sub_op<typename std::array<T,N>::value_type>,
                      const ad_vector<T,N>&>(std::forward<T>(lhs), rhs);
}

/************************************************************************
 * MULTIPLICATION 
 ***********************************************************************/
template <typename T, std::size_t N>
auto operator*(T&& lhs, ad_vector<T,N>&& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      mul_op<typename std::array<T,N>::value_type>,
                                                      ad_vector<T,N>&&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      mul_op<typename std::array<T,N>::value_type>,
                      ad_vector<T,N>&&>(std::forward<T>(lhs), rhs);
}

template <typename T, std::size_t N>
auto operator*(T&& lhs, const ad_vector<T,N>& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      mul_op<typename std::array<T,N>::value_type>,
                                                      const ad_vector<T,N>&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      mul_op<typename std::array<T,N>::value_type>,
                      const ad_vector<T,N>&>(std::forward<T>(lhs), rhs);
}

/************************************************************************
 * DIVISION
 ***********************************************************************/
template <typename T, std::size_t N>
auto operator/(T&& lhs, ad_vector<T,N>&& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      div_op<typename std::array<T,N>::value_type>,
                                                      ad_vector<T,N>&&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      div_op<typename std::array<T,N>::value_type>,
                      ad_vector<T,N>&&>(std::forward<T>(lhs), rhs);
}

template <typename T, std::size_t N>
auto operator/(T&& lhs, const ad_vector<T,N>& rhs) ->ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                                                      div_op<typename std::array<T,N>::value_type>,
                                                      const ad_vector<T,N>&> {
return ad_vector_bin_expr<decltype(std::forward<T>(lhs)),
                      div_op<typename std::array<T,N>::value_type>,
                     const ad_vector<T,N>&>(std::forward<T>(lhs), rhs);
}

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
