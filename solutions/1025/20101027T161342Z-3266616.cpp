#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
	int n;
	cin >> n;
	vector <int> a;
	int result = 0;
	int x;
	for (int i=0; i<n; i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=0; i<(n/2)+1; i++) {
		result+=(a[i]/2)+1;
	}
	cout << result; 
	system("pause");
	return 0;
}