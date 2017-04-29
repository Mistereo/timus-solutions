#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	bool* a = new bool[9999999];
	for(int i=0; i<9999999; i++)
		a[i]=0;
	string s;
	cin >> s;
	int n=s.length();
	int x;
	for(int i=0; i<n; i++){
		for(int j=1; j<8; j++) {
			x=atoi(s.substr(i,j).c_str());
			a[x]=1;
		}
	}
	x=1;
	while(a[x])
		x++;
	printf("%d\n",x);
	system("pause");
}