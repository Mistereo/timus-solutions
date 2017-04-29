#include <iostream>
#include <cmath>
using namespace std;
class point {
public:
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {
	};
	void scan() {
		scanf("%lf%lf", &x, &y);
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
int main() {
	point a,b,c,c1;
	double alfa,cc1;
	a.scan();
	b.scan();
	c.scan();
	alfa = ((b-c)%(a-c))/((a-c).len()*(b-c).len());
	if((b-c).len2()>=(a-b).len2() || alfa == 0)
		printf("YES");
	else {
		cc1 = (b-c).len()*alfa*2;
		c1 = ((c-a)*(((c-a).len()-cc1)/(c-a).len()))+a;
		printf("NO\n%.20Lf %.20Lf\n%.20Lf %.20Lf\n%.20Lf %.20Lf\n",a.x,a.y,b.x,b.y,c1.x,c1.y);
	}
	system("pause");
	return 0;
}