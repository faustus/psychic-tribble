#include <iostream>

#include "interpreter.h"
#include "add.h"

int main(int argc, char** argv){


   Variable v = 7.;

   std::cout<< eval(4+(v + 2))<<std::endl;

   return 0;

}
