#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class point {
public:
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {
	};
	void scan() {
		scanf("%lf%lf", &x, &y);
	}
	void print() {
		printf("%lf %lf\n",x,y);
	}
	point operator+(point a) {
		return point(x + a.x, y + a.y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	double operator%(point a) {
		return x * a.x + y * a.y;
	}
	double operator*(point a) {
		return x * a.y - y * a.x;
	}
	point operator*(double a) {
		return point(x*a, y * a);
	}
	point operator/(double a) {
		return point(x / a, y / a);
	}
	double len2() {
		return x * x + y*y;
	}
	double len() {
		return sqrt(x * x + y*y);
	}
};
class line {
public:
	double a,b,c;
	line(double a = 0, double b = 0, double c=0) : a(a), b(b), c(c) {};
	void asd(point aa, point bb){
		a = aa.y-bb.y;
		b = bb.x-aa.x;
		c = -((aa.y-bb.y)*aa.x+(bb.x-aa.x)*aa.y);
	}
	void print(){
		printf("%lf %lf %lf\n",a,b,c);
	};
};
int main() {
	int w,l,n;
	double x0,y0;
	scanf("%d%d%d",&w,&l,&n);
	double res=w*l;
	point v1(0,0),v2(0,w),v3(l,0),v4(l,w);
	point* a = new point[n];
	line ln[4] = {(0,0,0),(0,0,0),(0,0,0),(0,0,0)};
	bool in;
	for(int i=0; i<n; i++) a[i].scan();
	for(int i=0; i<n; i++) {
		if(a[i].x<=l && a[i].x>=0 && a[i].y>=0 && a[i].y<=w)
			in = true;
		else
			in = false;
		ln[0].asd(v1-a[i],v2-a[i]);
		ln[1].asd(v1-a[i],v3-a[i]);
		ln[2].asd(v2-a[i],v4-a[i]);
		ln[3].asd(v3-a[i],v4-a[i]);
		for(int j=0; j<4; j++) {
			double tmp = (ln[j].a*ln[j].a+ln[j].b*ln[j].b);
			x0 = -ln[j].a*ln[j].c/tmp;
			y0 = -ln[j].b*ln[j].c/tmp;
			if(ln[j].c*ln[j].c < tmp && abs(ln[j].c*ln[j].c - tmp) > 1e-9) {
				double d = 1-ln[j].c*ln[j].c/(tmp);
				double mult = sqrt (d/(tmp));
				point aaa(x0+ln[j].b*mult,y0-ln[j].a*mult);
				point bbb(x0-ln[j].b*mult,y0+ln[j].a*mult);
				if(((aaa+a[i]).x<l || abs((aaa+a[i]).x-l)<1e-9) && ((aaa+a[i]).x>=0) && (aaa+a[i]).y>=0 && ((aaa+a[i]).y<w || abs((aaa+a[i]).y-w)<1e-9)) {
					double alfa = acos(bbb%aaa);
					if(in) {
						res-= alfa/2;
						res+=(alfa - sin(alfa))/2;
					} else {
						res+=alfa/2;
						res-=(alfa - sin(alfa))/2;
					}
				}
			}
		}
	}
	printf("%.3lf\n",res);
	system("pause");
	return 0;
}