#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	char c;
	while(cin) {
		c = cin.get();
		if((c>='a' && c<= 'z') || (c>='A' && c<= 'Z')) s+=c;
		else {
			cout << string(s.rbegin(),s.rend());
			if (c!=EOF) cout << c;
			s="";
		}
	}
	return 0;
}