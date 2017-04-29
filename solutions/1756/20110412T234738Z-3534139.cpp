#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n,d1,d2,x,s=0;
	scanf("%d%d%d",&n,&d1,&d2);
	x=(n*d1+d2-1)/d2;
	for(int i=0; i<d2; i++) {
		if(s+x<d1*n) {
			printf("%d ",x);
			s+=x;
		} else {
			printf("%d ",d1*n-s);
			s+=d1*n-s;
		}
	} 
	system("pause");
	return 0;
}