#include <iostream>
#include <string>
#include <map>
using namespace std;
map<char,int> base;
string s;
bool foo(int b) {
	b--;
	int res=0;
	for(auto i=s.begin(); i!=s.end(); i++) {
		res+=(base[*i]);
		res%=b;
	}
	return res==0 ? 1 : 0;
}
int main() {
	char c = '0';
	char min = '0';
	bool x = false;
	for(int i=0; i<10; i++) {
		base[c] = i;
		c++;
	}
	c = 'A';
	for(int i=0; i<26; i++) {
		base[c] = i+10;
		c++;
	}
	while (cin >> c) {
		if(c>min)
			min=c;
		s+=c;
	}
	for (int i=base[min] + 1; i<37; i++) {
		if (i>1)
			if(foo(i)) {
				cout << i;
				x = 1;
				break;
			}
	}
	if(!x)
		cout << "No solution.";
	system("pause");
	return 0;
}