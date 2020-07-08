#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0)return a;
	else return gcd(b, a%b);
}
int main() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0 ;i < n; i++)
	{
		cin >> arr[i];
	}
	int d = -1, i, temp, j;
	int gcd1 = gcd(n,k);
	
	for(i = 0; i < gcd1; i++)	
	{
		j = i;
		temp = arr[i];
		while(1)
		{
			d = (j+k)%n  ;// rotate back
			if(d == i)break;
			arr[j] = arr[d];
			j = d;
		}
		arr[j] = temp;
	}
	for(int i = 0; i < n ; i++)
		cout << arr[i] << " ";
	return 0;
}
