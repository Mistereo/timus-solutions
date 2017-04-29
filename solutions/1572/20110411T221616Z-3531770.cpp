#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	int n,t,d,c=0;
	double s,s1;
	scanf("%d%d%d",&t,&d,&n);
	switch (t) {
	case 1:
		s = 2*d;
		break;
	case 2:
		s = d*sqrt(2.0);
		break;
	case 3:
		s = d;
		break;
	}
	for(int i=0; i<n; i++) {
		scanf("%d%d",&t,&d);
		s1 = d;
		if(t==1)
			s1*=2;
		else if(t==3)
			s1 = s1*sqrt(3.0)/2;
		if(s1<s || abs(s-s1)<1e-9)
			c++;
	}
	printf("%d", c);
	system("pause");
	return 0;
}