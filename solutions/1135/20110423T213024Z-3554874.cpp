#include <iostream>
using namespace std;
int main() {
	int n,res=0;
	scanf("%d",&n);
	char c;
	bool *a = new bool[n];
	for (int i=0; i<n; i++) {
		cin >> c;
		a[i] = (c=='<' ? 0 : 1);
	}
	bool x=true;
	while(x) {
		x = false;
		for(int i=0; i<n-1; i++) {
			if(a[i]==1 && a[i+1]==0) {
				swap(a[i],a[i+1]);
				x = true;
				i++;
				res++;
			}
		}
	}
	printf("%d\n",res);
	system("pause");
	return 0;
}