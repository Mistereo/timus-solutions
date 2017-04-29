#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct com {
	int id,n;
	short m;
};
int main() {
	int n;
	scanf("%d",&n);
	com* a = new com[n];
	for(int i=0; i<n; i++) {
		scanf("%d%d",&a[i].id,&a[i].m);
		a[i].n=i;
	}
	sort(a,a+n,[](com x,com y){return x.m==y.m ? x.n < y.n : x.m > y.m;});
	for(int i=0; i<n; i++)
		printf("%d %d\n",a[i].id,a[i].m);
	system("pause");
	return 0;
}