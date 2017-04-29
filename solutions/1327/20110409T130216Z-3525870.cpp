#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a,b,c=0;
	scanf("%d%d",&a,&b);
	for(int i=a; i<=b; i++)
		if(i%2!=0)
			c++;
	printf("%d\n",c);
	system("pause");
}