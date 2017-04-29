#include <iostream>
#include <string>
#include <set>
using namespace std;
set<int> m;
int main() {
	int n,x=0;
	for(int i=1; i<2147483648; i+=x){
		m.insert(i);
		x++;
	}
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&x);
		if(m.find(x)!=m.end())
			printf("1\n");
		else
			printf("0\n");
	}
	system("pause");
}