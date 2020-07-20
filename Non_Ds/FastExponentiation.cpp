#include <iostream>
#include <cmath>
using namespace std;
long long int power(int a, int n)
  {
  if(n == 0) return 1;
  long long int x = power(a, n/2);
  if(n%2 == 0)return x * x;
  else return a * x * x;
  }
  }
