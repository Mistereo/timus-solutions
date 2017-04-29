#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class point {
public:
	__int64 x, y;
	point(__int64 x = 0, __int64 y = 0) : x(x), y(y) {};
	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	void print() {
		printf("%lld %lld\n", x , y );
	}
	point operator+(point a) {
		return point(x + a.x, y + a.y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	__int64 operator%(point a) {
		return x * a.x + y * a.y;
	}
	__int64 operator*(point a) {
		return x * a.y - y * a.x;
	}
	__int64 len2() {
		return (x * x + y*y);
	}
	double len() {
		return sqrt(double(x * x + y*y));
	}
};
point snar;
double dist(point a, point b) {
	if((snar-a)%(b-a)>0 && (snar-b)%(a-b)>0)
		return abs(((snar-a)*(snar-b)))/(a-b).len();
	else
		return min( (a-snar).len(),(b-snar).len());
}
int main() {
	int n;
	double s=0;
	snar.scan();
	scanf("%d",&n);
	point *m = new point[n+1];
	for (int i=0; i<n; i++)
		m[i].scan();
	m[n]=m[0];
	for (int i=0; i<n; i++)
		s+=atan2(double((m[i]-snar)*(m[i+1]-snar)),double((m[i]-snar)%(m[i+1]-snar)));
	if(fabs(s) > 1e-9)
		printf("0.000\n");
	else {
		double mn = dist(m[0],m[1]);
		for (int i=1; i<n; i++)
			if (dist(m[i],m[i+1]) < mn)
				mn = dist(m[i],m[i+1]);
		printf("%.3lf\n",2*mn);
	}
	system("pause");
	return 0;
}