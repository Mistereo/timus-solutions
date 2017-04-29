#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n,mx=0,el,c,ans;
	scanf("%d",&n);
	int* a = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d",a[n/2]);
	system("pause");
	return 0;
}