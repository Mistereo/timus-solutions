#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int* a[3];
void foo(int k, int x=0) {
	int add = a[0][k] + a[1][k];
	a[2][k]=(add+x)%10;
	if(k>0) {
		if((add+x)>9)
			foo(k-1,(add+x)/10);
		else
			foo(k-1);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	a[0] = new int[n];
	a[1] = new int[n];
	a[2] = new int[n];
	for(int i=0; i<n; i++) {
		scanf("%d",&a[0][i]);
		scanf("%d",&a[1][i]);
	}
	foo(n-1);
	for(int i=0; i<n; i++)
		printf("%d",a[2][i]);
	system("pause");
}