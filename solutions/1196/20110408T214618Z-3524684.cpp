#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> set;
	int n,x,count=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		set.insert(x);
	}
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&x);
		if(set.find(x)!=set.end())
			count++;
	}
	printf("%d",count);
	system("pause");
}