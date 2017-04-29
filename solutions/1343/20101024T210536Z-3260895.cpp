#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(__int64 n)
{
	if (n <= 1)
		return false;
	for (__int64 j = 2; j * j <= n; j++)
		if (n % j == 0) return false;
	return true;
}
void main () {
	__int64 n;
	int x;
	cin >> x;
	if (x == 0)
		cout << "000000000003";
	else {
		cin >> n;
		if (n == 0)
			cout << "000000000003";
		else {
			for (int i = x; i<12; i++)
				n*=10;
			while (!is_prime(n)) {
				n++;
			}
			cout << n;
		}
	}
}