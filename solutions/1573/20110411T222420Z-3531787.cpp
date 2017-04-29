#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	int n,c=1,b,r,y;
	string s;
	scanf("%d%d%d%d",&b,&r,&y,&n);
	for(int i=0; i<n; i++) {
		cin >> s;
		if(s=="Red")
			c*=r;
		else if(s=="Yellow")
			c*=y;
		else if(s=="Blue")
			c*=b;
	}
	printf("%d", c);
	system("pause");
	return 0;
}