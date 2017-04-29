#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
class point {
    double x,y;
public:
    point(double x=0, double y=0):x(x), y(y) {};
    void scan(){
        scanf("%lf%lf",&x,&y);
    }
    point operator+(point a) {
        return point(x+a.x,y+a.y);
    }
	point operator-(point a) {
        return point(x-a.x,y-a.y);
    }
    double operator%(point a) {
        return x*a.x+y*a.y;
    }
    double operator*(point a) {
        return x*a.y- y*a.x;
    }
	point operator*(double a) {
        return point(x*a,y*a);
    }
	point operator/(double a) {
        return point(x/a,y/a);
    }
};
int main() {
	int n,
		c=0;
	cin >> n;
	point* a = new point[n];
	for(int i=0; i<n; i++) {
		a[i].scan();
	}
	int mx=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			c=0;
			for(int k=0; k<n; k++){
				if((a[j]-a[i])*(a[k]-a[i])==0 && i!=j)
					c++;
			}
			mx=max(c,mx);
		}
	}
	cout << mx << endl;
	system("pause");
    return 0;
}