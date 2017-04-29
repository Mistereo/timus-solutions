#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct peng {
	peng(string name):name(name),c(0) {};
	string name;
	short c;
};
bool operator<(peng a, peng b) {
	return a.c < b.c;
}
int main() {
	string s;
	int n;
	peng e("Emperor Penguin"), l("Little Penguin"), m("Macaroni Penguin");
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> s;
		if(s[0]=='E')
			e.c++;
		else if(s[0]=='L')
			l.c++;
		else
			m.c++;
		cin >> s;
	}
	cout << max(e,max(l,m)).name;
	return 0;
}