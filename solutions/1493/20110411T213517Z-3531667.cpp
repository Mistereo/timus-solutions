#include <iostream>
using namespace std;
bool isLucky(int n) {
	int s1=0,s2=0;
	for(int i=0; i<3; i++) {
		s1+=(n%10);
		n/=10;
	}
	for(int i=0; i<3; i++) {
		s2+=(n%10);
		n/=10;
	}
	return s1==s2 ? 1 : 0;
}
int main() {
	int n;
	scanf("%d",&n);
	if(isLucky(n+1) || isLucky(n-1))
		printf("Yes");
	else
		printf("No");
	system("pause");
	return 0;
}