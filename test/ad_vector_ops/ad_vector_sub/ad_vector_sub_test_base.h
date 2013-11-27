#ifndef __AD_VECTOR_SUB_TEST_BASE_H_
#define __AD_VECTOR_SUB_TEST_BASE_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_sub_test_base.h"

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
#endif
