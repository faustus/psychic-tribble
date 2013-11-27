#ifndef __AD_VECTOR_TEST_BASE_H_
#define __AD_VECTOR_TEST_BASE_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"

class ADVectorTest : public ::testing::Test{
   protected:
      ADVectorTest(){
         a = ad_vector<double,3>({1.0, 1.1, 1.2});
         b = ad_vector<double,3>({2.0, 2.1, 2.2});
         
      }

      ad_vector<double, 3> a;
      ad_vector<double, 3> b;
      ad_vector<double, 3> result;
};

class ADVectorAddTest : public ADVectorTest{
   protected:
      ADVectorAddTest(){
         add_res = ad_vector<double,3>({3.0, 3.2, 3.4});
         lit_add_res = ad_vector<double,3>({3.0, 3.1, 3.2});
      }
      ad_vector<double, 3> add_res;
      ad_vector<double, 3> lit_add_res;
};

class ADVectorSubTest : public ADVectorTest{
   protected:
      ADVectorSubTest(){
         sub_res = ad_vector<double,3>({1.0,1.0,1.0});
         lit_rhs_sub_res = ad_vector<double,3>({-1.5,-1.6,-1.7});
         lit_lhs_sub_res = ad_vector<double,3>({1.5,1.6,1.7});
      }
      ad_vector<double, 3> sub_res;
      ad_vector<double, 3> lit_rhs_sub_res;
      ad_vector<double, 3> lit_lhs_sub_res;
};

class ADVectorMulTest : public ADVectorTest{
   protected:
      ADVectorMulTest(){
         mul_res = ad_vector<double,3>({2.0, 2.31, 2.64});
         lit_mul_res = ad_vector<double,3>({3.0, 3.3, 3.6});
      }
      ad_vector<double, 3> mul_res;
      ad_vector<double, 3> lit_mul_res;
};

#endif
