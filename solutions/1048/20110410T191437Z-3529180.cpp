#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
short* a[3];
int main() {
	int n,x=0;
	scanf("%d",&n);
	a[0] = new short[n];
	a[1] = new short[n];
	a[2] = new short[n];
	for(int i=0; i<n; i++) {
		scanf("%d",&a[0][i]);
		scanf("%d",&a[1][i]);
	}
	for (int i=n-1; i>=0; i--) {
		a[2][i]=(a[0][i]+a[1][i])%10;
		a[1][i-1]+=(a[0][i]+a[1][i])/10;
	}
	for(int i=0; i<n; i++) {
		printf("%d",a[2][i]);
	}
	system("pause");
}