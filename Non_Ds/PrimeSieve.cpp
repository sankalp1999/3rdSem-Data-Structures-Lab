#include <iostream>
#include <vector>
using namespace std;

int main()
{
int n;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for(int i = 2; i*i <= n;i++)
{
  if(is_prime[i])
  {
  for(int j = i*i; j<=n; j+=i)
  {
    is_prime[j] = false;
  }
 }
}
// ln ln n complexity of code
