#ifndef __AD_VECTOR_ADD_TEST_H_
#define __AD_VECTOR_ADD_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"

TEST_F(ADVectorAddTest, PlusClass){
   result = a + b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],add_res[i]);
}

TEST_F(ADVectorAddTest, PlusEqualClass){
   result = a;
   result += b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],add_res[i]);
}

TEST_F(ADVectorAddTest, PlusEqualExprClass){
   result+= a+b;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],add_res[i]);
}

TEST_F(ADVectorAddTest, PlusLHSNonClass){
   result = a + 2.;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_add_res[i]);
}

TEST_F(ADVectorAddTest, PlusRHSNonClass){
   result = 2. + a;
   for(std::size_t i=0; i<3; ++i)
      ASSERT_DOUBLE_EQ(result[i],lit_add_res[i]);
}



#endif
