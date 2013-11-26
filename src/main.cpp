#include <array>
#include <algorithm>
#include <initializer_list>
#include <type_traits>
#include <iostream>


#include "ad_vector_base.h"
int main()
{
  using namespace std;

  try
  {
    {
      cout << "CASE 1:\n";
      ad_vector<double,3> a{1.0, 1.1, 1.2};
      ad_vector<double,3> b{2.0, 2.1, 2.2};
      ad_vector<double,3> c{3.0, 3.1, 3.2};
      ad_vector<double,3> d{4.0, 4.1, 4.2};
      ad_vector<double,3> result = a + b + c + d;
      cout << '[' << &result << "]: " << result << "\n";
      result = result + 2.;
      cout<< result<<endl;
      result = 2. + result;
      cout << result<<endl;

      result = result - a;
      cout << result<<endl;
      result = a - b;
      cout << result <<endl;

      result = a*b;
      cout <<result <<endl;

      result = a/b;
      cout<<result<<endl;
    }
  }
  catch (...)
  {
    return 1;
  }
}
