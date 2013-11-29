#include <iostream>
#include <type_traits>

#include "ad_vector_base.h"
int main()
{
  try
  {
    {
      std::cout << "CASE 1:\n";
      ad_vector<double,3> a{1.0, 1.1, 1.2};
      ad_vector<double,3> b{2.0, 2.1, 2.2};
      ad_vector<double,3> c{3.0, 3.1, 3.2};
      ad_vector<double,3> d{4.0, 4.1, 4.2};
      ad_vector<double,3> result;

      result = pow(a+b,2.);
      std::cout<< result <<std::endl;
      std::cout<< a <<std::endl;
    }
  }
  catch (...)
  {
    return 1;
  }
}
