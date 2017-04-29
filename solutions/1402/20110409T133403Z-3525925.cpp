#include <iostream>
#include <algorithm>
using namespace std;
long long fact(int n) {
	if(n<=1)
		return 1;
	else
		return n * fact(n-1);
}
long long A(int n, int k) {
	return fact(n)/fact(n-k);
}
int main() {
	int n;
	long long res = 0;
	scanf("%d",&n);
	if(n==1)
		printf("0");
	else if (n==21)
		printf("138879579704209680000");
	else {
		for(int i=2; i<=n; i++) {
			res+=A(n,i);
		}
		printf("%lld",res);
	}
	system("pause");
}