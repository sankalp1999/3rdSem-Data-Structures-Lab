#include <iostream>
using namespace std;

/*
Suppose y > x
let x = g * x1
let y = g * x2

y - x = g * (x2 - x1)

Gcd of x and y is equal to gcd of gcd(x,y-x).
Using this, GCD(x,y) = GCD(x,y%x) since we can subtract x till we reach below x.

In each iteration, we are atleast reducing by half of min(x,y)
Hence O(log(min(x,y))

The recursive code can also be thought of as the 
Euclid long division method to find HCF that we did in school.
*/

long long int gcd(long long int a, long long int b)
{
    if(b == 0)
    {
        return a;		
    }
    else
    {
        return gcd(b, a%b);
    }
}
int main() {
	
   return 0;
}
