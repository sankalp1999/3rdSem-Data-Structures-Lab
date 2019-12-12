#include <iostream>
using namespace std;
// Adopted this from CP-algorithms or emaxx-english. Thanks a lot to them!
int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    cout << "x : "<< x << " x1: " << x1 << " y: " << y << " y1: " << y1 << endl;
    return d;
}
int main() {
	int x, y;
	cout << gcd(315, 1015, x, y) << endl;
	cout << x << " " << y;
	return 0;
}
