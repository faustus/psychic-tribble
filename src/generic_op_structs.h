#ifndef __GENERIC_OP_STRUCTS_H_
#define __GENERIC_OP_STRUCTS_H_

template <typename T>
struct add_op{
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

template <typename T>
struct sub_op{
   static T apply(const T& a, const T& b){
      return a - b;
   }

   static T apply(T&& a, const T& b){
      a -= b;
      return std::move(a);
   }

   static T apply(const T& a, T&& b){
      return a - b;
   }

   static T apply(T&& a, T&& b){
      a -= b;
      return std::move(a);
   }
};

template <typename T>
struct mul_op{
   static T apply(const T& a, const T& b){
      return a * b;
   }

   static T apply(T&& a, const T& b){
      a *= b;
      return std::move(a);
   }

   static T apply(const T& a, T&& b){
      b *= a;
      return std::move(b);
   }

   static T apply(T&& a, T&& b){
      a *= b;
      return std::move(a);
   }
};

template <typename T>
struct div_op{
   static T apply(const T& a, const T& b){
      return a / b;
   }

   static T apply(T&& a, const T& b){
      a /= b;
      return std::move(a);
   }

   static T apply(const T& a, T&& b){
      return a / b;
   }

   static T apply(T&& a, T&& b){
      a /= b;
      return std::move(a);
   }
};

#endif
