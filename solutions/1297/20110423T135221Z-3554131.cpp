#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	string s, res="",tmp="";
	int mx = 0,l,r;
	cin >> s;
	int ssize = s.size();
	for (int i=0; i<ssize; i++) {
		l=-1;
		r=1;
		tmp=s[i];
		while (1) {
			if ((i+l>=0 && i+r<ssize) && s[i+l] == s[i+r])
				tmp = s[i+l] + tmp + s[i+r];
			else {
				if (tmp.size() > mx) {
					res = tmp;
					mx = tmp.size();
				}
				break;
			}
			l--;
			r++;
		}
	}
	for (int i=0; i<ssize; i++) {
		l=i;
		r=i+1;
		tmp="";
		while (1) {
			if ((l>=0 && r<ssize) && s[l] == s[r])
				tmp = s[l] + tmp + s[r];
			else {
				if (tmp.size() > mx) {
					res = tmp;
					mx = tmp.size();
				}
				break;
			}
			l--;
			r++;
		}
	}
	cout << res;
	system("pause");
	return 0;
}