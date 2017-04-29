#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int alfa;
	double  v,k,res=0,x=1;
	scanf("%lf%d%lf",&v,&alfa,&k);
	while (x>1e-19) {
		x=v*v*sin(2*alfa*3.1415926535/180)/10;
		res+=x;
		v/=sqrt(k);
	}
	printf("%.2lf\n",res);
	system("pause");
	return 0;
}