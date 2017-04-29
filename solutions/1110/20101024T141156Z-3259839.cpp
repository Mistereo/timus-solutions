#include <iostream>
using namespace std;
int main() {
	int n,m,y,test;
	bool x = 0;
	cin >> n >> m >> y;
	for (int i = 0; i < m; i++) {
		test=1;
		for (int j = 0; j < n; j++) {
			test = (test*(i%m))%m;
		}
		if (test == y) {
			cout << i << " ";
			x = true;
		}
	}
	if (!x)
		cout << "-1";
}