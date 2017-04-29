#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
vector<string> dict;
int nc = 0;
bool operator%(string a, string b) {
	int al = a.length();
	if(al != b.length() || a==b)
		return false;
	int x = 0;
	for (int i=0; i<al; i++) {
		if(a[i]!=b[i])
			x++;
		if(x>1)
			return false;
	}
	return true;
}
string find(string s) {
	for(int i=0; i<dict.size(); i++) {
		if(s%dict[i]) {
			nc++;
			return dict[i];
		}
	}
	return s;
}
int main() {
	char c='0';
	string s;
	cin >> s;
	while (s!="#") {
		dict.push_back(s);
		cin >> s;
	}
	s = "";
	int asd=scanf("%c",&c);
	while(asd!=EOF) {
		if(c>='a' && c<= 'z')
			s+=c;
		else {
			cout << find(s) << c;
			s="";
		}
		asd = scanf("%c",&c);
	}
	cout << find(s);
	cout << endl << nc;
	return 0;
}