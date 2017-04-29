#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	int n,c=0;
	string s;
	set<string> set;
	cin >> n;
	getline(cin,s);
	for(int i=0; i<n; i++) {
		getline(cin,s);
		if(set.find(s)==set.end()) {
			set.insert(s);
		}
		else
			c++;
	}
	printf("%d", c);
	system("pause");
	return 0;
}