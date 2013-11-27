#ifndef __AD_VECTOR_DIV_TEST_H_
#define __AD_VECTOR_DIV_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"
#include "ad_vector_div_test_base.h"

TEST_F(ADVectorDivTest, DivideClass){
   result = b / a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],div_res[i]);
}

TEST_F(ADVectorDivTest, DivideEqualClass){
   result = b;
   result /= a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],div_res[i]);
}

TEST_F(ADVectorDivTest, DivideEqualExprClass){
   result = ad_vector<double,3>({1.,1.,1.});
   result/= a/b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],div_res[i]);
}

TEST_F(ADVectorDivTest, DivideLHSNonClass){
   result = b / .5;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_lhs_div_res[i]);
}

TEST_F(ADVectorDivTest, DivideRHSNonClass){
   result = .5 / b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_rhs_div_res[i]);
}



#endif
