#include <iostream>
using namespace std;
int main() {
	int n,k;
	cin >> n >> k;
	if(k>n) k=n;
	cout << (n*2+(k-1))/k << endl;
}