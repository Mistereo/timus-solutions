#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,k;
	string s;
	scanf("%d",&n);
	cin >> s;
	k = s.length();
	long res = 1;
	while(n>k) {
		res*=n;
		n-=k;
	}
	if(n%k==0)
		res*=k;
	else if(n>0)
		res*=n;
	printf("%d\n",res);
	system("pause");
}