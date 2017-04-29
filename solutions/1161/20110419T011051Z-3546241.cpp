#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main () {
	int n;
	cin >> n;
	long long *a = new long long[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	if (n==1) {
		printf("%d.00",a[0]);
	} else {
		sort(a,a+n,[](long long x,long long y){return x > y;});
		double x = 2*sqrt((double)(a[0]*a[1]));
		for(int i=2; i<n; i++) {
			x = 2*sqrt(x*(double)a[i]);
		}
		printf("%.2lf",x);
	}
	system("pause");
	return 0;
}