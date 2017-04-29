#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int n,k;
	cin >> n >> k;
	cout << (n*(n-1))/2 - k;
	system("pause");
	return 0;
}