#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void main () {
	int n; 
	cin >> n;
	if(n==1)
		cout << 1 << " " << 2 << " " << 3;
	else if(n==2)
		cout << 3 << " " << 4 << " " << 5;
	else 
		cout << -1;
}