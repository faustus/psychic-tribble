#ifndef __AD_VECTOR_MUL_TEST_H_
#define __AD_VECTOR_MUL_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"

TEST_F(ADVectorMulTest, PlusClass){
   result = a * b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, PlusEqualClass){
   result = a;
   result *= b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, PlusEqualExprClass){
   result*= a+b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, PlusLHSNonClass){
   result = a * 2.;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_mul_res[i]);
}

TEST_F(ADVectorMulTest, PlusRHSNonClass){
   result = 2. * a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_mul_res[i]);
}



#endif
