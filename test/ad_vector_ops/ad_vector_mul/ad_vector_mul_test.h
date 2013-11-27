#ifndef __AD_VECTOR_MUL_TEST_H_
#define __AD_VECTOR_MUL_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"
#include "ad_vector_mul_test_base.h"

TEST_F(ADVectorMulTest, MultiplyClass){
   result = a * b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, MultiplyEqualClass){
   result = a;
   result *= b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, MultiplyEqualExprClass){
   result = ad_vector<double,3>({1.,1.,1.});
   result*= a*b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],mul_res[i]);
}

TEST_F(ADVectorMulTest, MultiplyLHSNonClass){
   result = a * 3.;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_mul_res[i]);
}

TEST_F(ADVectorMulTest, MultiplyRHSNonClass){
   result = 3. * a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_mul_res[i]);
}



#endif
