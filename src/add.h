#ifndef __BIN_EXPR_ADD_H_
#define __BIN_EXPR_ADD_H_

template<class T, std::size_t N> class ADType;

template <typename T>
struct ad_plus_op{
   static T apply(const T& a, const T& b){
      return a+b;
   }

   static T apply(T&& a, const T&b){
      a+=b;
      return std::move(a);
   }

   static T apply(const T& a, T&& b){
      b+= a;
      return std::move(b);
   }

   static T apply(T&& a, T&&b){
      a+= b;
      return std::move(a);
   }
};

template <typename T, class ADType<T, std::size_t N>>
struct ad_data_plus_op{
   static ADType apply(const ADType& a, const T& b){
      return a+b;
   }

   static ADType apply(const T& a, const ADType& b){
      return a+b;
   }

   static ADType apply(ADType&& a, const T&b){
      a+=b;
      return std::move(a);
   }

   static ADType apply(T&& a, const ADType&b){
      return a+b;
   }

   static ADType apply(const T& a, ADType&& b){
      b+= a;
      return std::move(b);
   }

   static ADType apply(const ADType& a, const T& b){
      return a+b;
   }

   static ADType apply(ADType&& a, T&&b){
      a+= b;
      return std::move(a);
   }

   static ADType apply(T&& a, ADType&& b){
      b+= a;
      return std::move(b);
   }

};
#endif
