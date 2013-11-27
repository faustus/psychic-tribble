#ifndef __AD_VECTOR_SUB_TEST_H_
#define __AD_VECTOR_SUB_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"
#include "ad_vector_sub_test_base.h"

TEST_F(ADVectorSubTest, MinusClass){
   result = b - a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],sub_res[i]);
}

TEST_F(ADVectorSubTest, MinusEqualClass){
   result = b;
   result -= a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],sub_res[i]);
}

TEST_F(ADVectorSubTest, MinusEqualExprClass){
   result+= b-a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],sub_res[i]);
}

TEST_F(ADVectorSubTest, MinusLHSNonClass){
   result = b - .5;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_lhs_sub_res[i]);
}

TEST_F(ADVectorSubTest, MinusRHSNonClass){
   result = .5 - b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_rhs_sub_res[i]);
}



#endif
