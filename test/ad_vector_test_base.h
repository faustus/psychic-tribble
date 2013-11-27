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

#endif
