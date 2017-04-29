#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (b==0) return a;
	return gcd(b,a%b);
}
int main() {
	int n,m;
	cin >> n >> m;
	int count=1;
	n--;
	m--;
	count=gcd(m,n);
	if (count != 1){
		m/=count;
		n/=count;
	}
	cout << ((m+n-1)*count);
}