#include <iostream>
using namespace std;
__int64 gcd(__int64 a, __int64 b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
__int64 binpow (__int64 a, __int64 x, __int64 n) {
	__int64 res = 1;
	while (x) {
		if (x & 1)
			res = (res*a)%n;
		a =(a*a)%n;
		x >>= 1;
	}
	return res;
}
__int64 phi (__int64 n) {
	__int64 result = n;
	for (__int64 i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
		if (n > 1)
			result -= result / n;
		return result;
}
void main () {
	__int64 a,n;
	cin >> a >> n;
	if(gcd(a,n)>1)
		cout << 0 << endl;
	else {
		__int64 phin = phi(n);
		__int64 answer = phin;
		for (__int64 i=2; i*i<=answer; i++) {
			while(answer%i==0) {
				if(binpow(a,answer/i,n)%n==1)
					answer /= i;
				else
					break;
			}
		}
		cout << answer << endl;
	}
	system("pause");
}