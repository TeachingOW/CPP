#include <iostream>
using namespace std;
template<typename T, int N>
T power(T num)
{
  T r = 1 /* NRVO variable */;
  for(int i = 0; i < N; i++) {
    r = static_cast<T>(static_cast<<dependent type>>(r) * num);
  }
  
  return r;
}

/* First instantiated from: insights.cpp:10 */
#ifdef INSIGHTS_USE_TEMPLATE
template<>
int power<int, 4>(int num)
{
  int r = 1;
  for(int i = 0; i < 4; i++) {
    r = static_cast<int>(r * num);
  }
  
  return r;
}
#endif


int main()
{
  std::cout.operator<<(power<int, 4>(5));
  return 0;
}
