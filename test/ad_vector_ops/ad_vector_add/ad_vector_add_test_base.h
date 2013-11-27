#ifndef __AD_VECTOR_ADD_TEST_BASE_H_
#define __AD_VECTOR_ADD_TEST_BASE_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_test_base.h"

class ADVectorAddTest : public ADVectorTest{
   protected:
      ADVectorAddTest(){
         add_res = ad_vector<double,3>({3.0, 3.2, 3.4});
         lit_add_res = ad_vector<double,3>({3.0, 3.1, 3.2});
      }
      ad_vector<double, 3> add_res;
      ad_vector<double, 3> lit_add_res;
};

#endif
