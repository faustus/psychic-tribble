#ifndef __AD_VECTOR_DIV_TEST_BASE_H_
#define __AD_VECTOR_DIV_TEST_BASE_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"

class ADVectorDivTest : public ADVectorTest{
   protected:
      ADVectorDivTest(){
         div_res = ad_vector<double,3>({2.0,2.1/1.1,2.2/1.20});
         lit_rhs_div_res = ad_vector<double,3>({0.5/2., 0.5/2.1, 0.5/2.2});
         lit_lhs_div_res = ad_vector<double,3>({4.0, 4.2, 4.4});
      }
      ad_vector<double, 3> div_res;
      ad_vector<double, 3> lit_rhs_div_res;
      ad_vector<double, 3> lit_lhs_div_res;
};

#endif
