#include <iostream>
#include <set>
using namespace std;
int main() {
	int n,k,p,c=0;
	scanf("%d%d%d",&n,&k,&p);
	double sum=n;
	while(sum>k){
		c++;
		sum=sum-sum*p/100;
	}
	printf("%d\n",c);
	system("pause");
}