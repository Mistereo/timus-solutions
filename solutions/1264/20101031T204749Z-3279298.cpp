#include <iostream>
using namespace std;
int main() {
	int n,m;
	int s = 0;
	cin >> n;
	cin >> m;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<=m; j++) {
			s++;
		}
	}
	cout << s;
}