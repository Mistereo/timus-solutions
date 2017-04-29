#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void main () {
	char c;
	int k,n; 
	cin >> n;
	vector<int> a;
	int x;
	for(int i=0; i<n; i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	cin >> c;
	cin >> c;
	cin >> c;
	cin >> k;
	for(int i=0; i<k; i++) {
		cin >> x;
		cout << a[x-1] << endl;
	}
	//***************
	cout << endl;
	system("pause");
}