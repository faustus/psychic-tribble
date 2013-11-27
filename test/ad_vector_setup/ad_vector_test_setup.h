#ifndef __AD_VECTOR_SETUP_H_
#define __AD_VECTOR_SETUP_H_

#include <type_traits>

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"
//WARNING:
// SOME OF THESE TESTS ASSUME ADDITION IS IMPLEMENTED CORRECTLY.
// YOU HAVE BEEN WARNED OF THE OUROBOROS!!

TEST(ADVectorType, NoParams){
   bool val = std::is_same<double, ad_vector<>::value_type>::value;
   ASSERT_TRUE(val);
}

TEST(ADVectorType, FloatParams){
   bool val = std::is_same<float, ad_vector<float,1>::value_type>::value;
   ASSERT_TRUE(val);
}

TEST(ADVectorType, DoubleParams){
   bool val = std::is_same<double, ad_vector<double,1>::value_type>::value;
   ASSERT_TRUE(val);
}

TEST(ADVectorCtor, Default){
   ad_vector<double,3> q;
   ASSERT_DOUBLE_EQ(q[0] , 0.);
   ASSERT_DOUBLE_EQ(q[1] , 0.);
   ASSERT_DOUBLE_EQ(q[2] , 0.);
}

TEST_F(ADVectorTest, CopyCtor){
   ad_vector<double,3> c(a);
   ASSERT_DOUBLE_EQ(c[0] , 1.0);
   ASSERT_DOUBLE_EQ(c[1] , 1.1);
   ASSERT_DOUBLE_EQ(c[2] , 1.2);
}

TEST_F(ADVectorTest, InitializerListCtor){
   ASSERT_DOUBLE_EQ(a[0] , 1.0);
   ASSERT_DOUBLE_EQ(a[1] , 1.1);
   ASSERT_DOUBLE_EQ(a[2] , 1.2);
}

TEST_F(ADVectorTest, ExprCtor){
   ad_vector<double,3>c(a+b);
   ASSERT_DOUBLE_EQ(c[0] , 3.0);
   ASSERT_DOUBLE_EQ(c[1] , 3.2);
   ASSERT_DOUBLE_EQ(c[2] , 3.4);
}

TEST_F(ADVectorTest, MoveAssign){
   b= ad_vector<double,3>({1.0, 1.1, 1.2});
   ASSERT_DOUBLE_EQ(b[0] , 1.0);
   ASSERT_DOUBLE_EQ(b[1] , 1.1);
   ASSERT_DOUBLE_EQ(b[2] , 1.2);
}

TEST_F(ADVectorTest, CopyAssign){
   const ad_vector<double,3> c(a);
   b=c;
   ASSERT_DOUBLE_EQ(b[0] , 1.0);
   ASSERT_DOUBLE_EQ(b[1] , 1.1);
   ASSERT_DOUBLE_EQ(b[2] , 1.2);
}

TEST_F(ADVectorTest, ExprAssign){
   result = a+b;
   ASSERT_DOUBLE_EQ(result[0] , 3.0);
   ASSERT_DOUBLE_EQ(result[1] , 3.2);
   ASSERT_DOUBLE_EQ(result[2] , 3.4);
}

#endif
