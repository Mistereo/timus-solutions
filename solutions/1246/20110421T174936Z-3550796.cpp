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
		return sqrt(x*x + y*y);
	}
};
int main() {
	int n;
	double sum=0;
	scanf("%d",&n);
	point *v = new point[n];
	for (int i=0; i<n; i++) {
		v[i].scan();
	}
	for (int i=0; i<n-1; i++)
		sum+=(v[i].y+v[i+1].y)*(v[i+1].x-v[i].x)/2;
	sum+=(v[0].y+v[n-1].y)*(v[0].x-v[n-1].x)/2;
	printf(sum > 0 ? "cw" : "ccw");
	return 0;
}