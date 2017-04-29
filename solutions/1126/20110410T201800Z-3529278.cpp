#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n,x;
	scanf("%d",&n);
	int* a = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	printf("%d\n",*max_element(a,a+n));
	int i=0;
	scanf("%d",&x);
	while(x!=-1) {
		a[i]=x;
		printf("%d\n",*max_element(a,a+n));
		i++;
		if(i==n)
			i=0;
		scanf("%d",&x);
	}
	system("pause");
}