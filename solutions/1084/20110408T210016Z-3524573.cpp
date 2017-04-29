#include <iostream>
#include <cmath>
using namespace std;
class point {
	int x,y;
public:
	point(int x=0,int y=0):x(x),y(y){}
	void scan() {scanf("%d%d",&x,&y); }
	int len2() {return x*x+y*y;}
	point operator+(point a){return point(x+a.x, y+a.y); }
	point operator-(point a) {return point(x-a.x, y-a.y); }
	point operator*(int a) {return point(x*a,y*a); }
	point operator/(int a) {return point(x/a,y/a); }
	int operator*(point a) {return x*a.y - y*a.x; }
	int  operator%(point a) {return a.x*x+a.y*y; }
	bool operator==(point a) {return (x==a.x) && (y==a.y); }
};
int main() {
	const double PI = 3.1415926535;
	long double d,r;
	scanf("%lf%lf",&d,&r);
	if(r<d/2)
		printf("%.3lf\n",r*r*PI);
	else if(r*r>(d*d/2))
		printf("%.3lf\n",d*d);
	else {
		long double x = acos(((-abs(r*r-d*d/4)+d*d/4)/(abs(r*r-d*d/4)+d*d/4)));
		long double res = (r*r*(x - sin(x)))/2;
		res = (double)(r*r*PI) - 4*res;
		printf("%.3lf\n",res);
	}
	system("pause");
}