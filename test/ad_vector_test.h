#ifndef __AD_VECTOR_TEST_H_
#define __AD_VECTOR_TEST_H_

#include "gtest/gtest.h"
#include "ad_vector_base.h"

class ADVectorTest : public ::testing::Test{
   public:
      ADVectorTest(){
         a = ad_vector<double,3>({1.0, 1.1, 1.2});
         b = ad_vector<double,3>({2.0, 2.1, 2.2});
      }

      virtual ~ADVectorTest(){
      }
      virtual void SetUp(){

      }

      virtual void TearDown(){

      }

   private:
      ad_vector<double, 3> a;
      ad_vector<double, 3> b;
      ad_vector<double, 3> result;
};

TEST(ADVectorCtor, Default){
   ad_vector<double,3> q;
   ad_vector<double,3> c{1.,2.,3.};
   ASSERT_DOUBLE_EQ(c[0], 1.);
   ASSERT_DOUBLE_EQ(c[1], 2.);
   ASSERT_DOUBLE_EQ(c[2], 3.);
}
#endif
