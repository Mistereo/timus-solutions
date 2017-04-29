#include <iostream>
using namespace std;
int main() {
	const int c = 100000;
	double p,q;
	cin >> p >> q;
	int n = (int)(p*1000);
	int m = (int)(q*1000);
	long x = 0;
	if(n==m)
		cout << "ololo";
	else
		while(n*x/c == m*x/c || (n*x/c)*c == n*x || (m*x/c)*c == m*x)
			x++;
	cout << x;
}