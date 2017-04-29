#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
	short num[]={1, 3, 2, 6, 4, 5};
	string s;
	cin >> s;
	int x=0,j=0;
	for(int i=s.length()-1; i>=0; i--) {
		x+=((int)s[i]-48)*num[j];
		x%=7;
		j++;
		if(j==6)
			j=0;
	}
	cout << x;
	system("pause");
}