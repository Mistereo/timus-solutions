#include <iostream>
using namespace std;

int binpow (int a, int x, int n) {
	int res = 1;
	while (x) {
		if (x & 1)
			res = (res*a)%n;
		a =(a*a)%n;
		x >>= 1;
	}
	return res;
}


int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
		if (n > 1)
			result -= result / n;
		return result;
}
void main()	{

	int q,e,n,c,d,phin;
	cin >> q;
	for(int i=0; i<q; i++) {
	cin >> e >> n >> c;
	phin = phi(n);
	d = binpow(e,phi(phin)-1,phin);
	int cd = binpow(c,d,n);
	int m = cd%n;
	cout << m << endl;
	}
	system("pause");
}