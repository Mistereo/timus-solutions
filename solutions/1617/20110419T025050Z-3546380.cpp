#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main () {
	int n,x;
	cin >> n;
	short a[101];
	memset(a,0,101*sizeof(short));
	for (int i=0; i<n; i++) {
		cin >> x;
		a[x-600]++;
	}
	int c = 0;
	for (int i=0; i<101; i++) {
		c+=(a[i]/4);
	}
	cout << c << endl;
	system("pause");
	return 0;
}