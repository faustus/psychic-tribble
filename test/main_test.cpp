#include <iostream>

#include "gtest/gtest.h"
#include "ad_vector_test_list.h"
int main(int argc, char** argv){
   ::testing::InitGoogleTest(&argc,argv);
   return RUN_ALL_TESTS();
}
