#include <iostream>
#include <string>
using namespace std;
int main() {
	int n,q,x;
	scanf("%d",&n);
	int* a = new int[n+1];
	a[0] = 0;
	for (int i=0; i<n; i++) {
		scanf("%d",&a[i+1]);
		a[i+1]+=a[i];
	}
	scanf("%d",&q);
	for(int i=0; i<q; i++) {
		scanf("%d%d",&x,&n);
		printf("%d\n", a[n]-a[x-1]);
	}
	return 0;
}