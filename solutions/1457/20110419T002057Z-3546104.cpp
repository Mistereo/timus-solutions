#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n,x;
	double s=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		s+=x;
	}
	printf("%lf",s/n);
	system("pause");
	return 0;
}