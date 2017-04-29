#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
	long long n,m,sum=0,t;
	bool x=0;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> t;
		sum+=t;
		if(n*3<sum) {
			cout << "Free after " << i+1 << " times.";
			x=1;
			break;
		}
	}
	if(!x)
		cout << "Team.GOV!";
	system("pause");
}