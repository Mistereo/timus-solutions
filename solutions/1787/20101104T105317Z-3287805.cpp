#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void main () {
	int k,n; 
	cin >> k >> n;
	int asd = 0;
	int x;
	for(int i=0; i<n; i++) {
		cin >> x;
		asd+=x;
		if(asd<=k)
			asd=0;
		else
			asd-=k;
	}
	cout << asd;
	system("pause");
}