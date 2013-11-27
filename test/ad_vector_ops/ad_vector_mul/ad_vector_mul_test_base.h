#ifndef __AD_VECTOR_MUL_TEST_BASE_H_
#define __AD_VECTOR_MUL_TEST_BASE_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"
#include "ad_vector_mul_test_base.h"

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
