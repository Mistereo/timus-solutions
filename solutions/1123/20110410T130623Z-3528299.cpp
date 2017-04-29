#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int n;
string s;
void foo(int k){
	if(s[k]=='9') {
		for(int i=k; i<s.length(); i++)
			s[i]='0';
		foo(k-1);
	} else {
		s[k]++;
		for(int i=k+1; i<s.length(); i++)
			s[i]='0';
	}
}
int main() {
	cin >> s;
	n=(s.length()+1)/2;
	for(int i=n, j=n-1-s.length()%2; i<s.length(); i++,j--) {
		if(s[i]>s[j]) {
			foo(n-1);
			break;
		} else if(s[i]!=s[j])
			break;
	}
	for(int i=s.length()-1, j=0; i>=n; i--,j++) {
		s[i]=s[j];
	}
	cout << s;
	system("pause");
	return 0;
}