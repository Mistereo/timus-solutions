#include <iostream>
using namespace std;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	short *a = new short[n];
	for (int i=0; i<n; i++) 
		scanf("%d",&a[i]);
	for (int i=k%n, j=0; j<10; i++,j++) {
		if(i>=n)
			i=0;
		printf("%d",a[i]);
	}
	return 0;
}