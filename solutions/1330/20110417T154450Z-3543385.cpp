#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,q,sum=0,x;
	scanf("%d",&n);
	int* a = new int[n+1];
	a[0] = 0;
	for (int i=0; i<n; i++) {
		scanf("%d",&x);
		sum+=x;
		a[i+1] = sum;
	}
	scanf("%d",&q);
	for(int i=0; i<q; i++) {
		scanf("%d%d",&x,&n);
		printf("%d\n", a[n]-a[x-1]);
	}
	return 0;
}