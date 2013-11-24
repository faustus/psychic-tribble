#ifndef __ADTYPE_OPERATOR_TEMPLATES_H_
#define __ADTYPE_OPERATOR_TEMPLATES_H_

#include <algorithm>
#include <type_traits>
#include <utility>

#include "add.h"

template<class T, std::size_t N> class ADType;

template<typename LExpr, typename BinOp, typename RExpr>
class ADTypeExpr{
   public:
      //prohibit basic ctor...
      ADTypeExpr() = delete;
      //... and copy ctor...
      ADTypeExpr(const ADTypeExpr&) = delete;
      //...and assigns
      ADTypeExpr& operator=(const ADTypeExpr&) = delete;

      //param c_tor
      ADTypeExpr(LExpr lhs, RExpr, rhs):
         _lhs(std::forward<LExpr>(lhs)),
         _rhs(std::forward<RExpr>(rhs)){}

      //set moves as default
      //compiler will provide
      ADTypeExpr(ADTypeExpr&&) = default;
      ADTypeExpr& operator=(ADTypeExpr&&) = default;

      //here begins the nasty
      
      /************************************************************************
       *    ADDITION
       ***********************************************************************/
      template<typename RE>
      auto operator+(RE&& rhs) const->
         ADTypeExpr<
            ADTypeExpr<LExpr,BinOP,RExpr> const&, 
                  BinOp,
                  decltype(std::forward<RE>(rhs)>{
         //return hay-nus cast
         return ADTypeExpr<
                  ADTypeExpr<LExpr,BinOP,RExpr> const&, 
                        BinOp, 
                        decltype(std::forward<RE>(rhs)>(*this,
                                                        std::forward<RE>(rhs));
      }


      /************************************************************************
       *    Monkey functions
       *    |--> those functions defined to monkey with things.
       *    |--> DRAGONS BE HERE!
       ***********************************************************************/

      auto le()-> typename std::add_lvalue_reference<LExpr>::type{
         return _lhs; 
      }

      auto le() const ->
         typename std::add_lvalue_reference<
                       typename std::add_const<LExpr>::type>::type{
         return _lhs; 
      }

      auto re()-> typename std::add_lvalue_reference<RExpr>::type{
         return _rhs; 
      }

      auto re() const ->
         typename std::add_lvalue_reference<
                       typename std::add_const<RExpr>::type>::type{
         return _rhs; 
      }
      
      /************************************************************************
       *    Private Members
       ***********************************************************************/
   private:
      LExpr _lhs;
      RExpr _rhs;
};

#endif
