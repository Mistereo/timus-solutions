#include <iostream>
using namespace std;
class point {
	int x,y;
public:
	point(int x=0,int y=0):x(x),y(y){}
	void scan() {
		scanf("%d%d",&x,&y);
	}
	int len2() {
		return x*x+y*y;
	}
	point operator+(point a){
		return point(x+a.x, y+a.y);
	}
	point operator-(point a) {
		return point(x-a.x, y-a.y);
	}
	point operator*(int a) {
		return point(x*a,y*a);
	}
	point operator/(int a) {
		return point(x/a,y/a);
	}
	int operator*(point a) {
		return x*a.y - y*a.x;
	}
	int  operator%(point a) {
		return a.x*x+a.y*y;
	}
	bool operator==(point a) {
		return (x==a.x) && (y==a.y);
	}
};
int main() {
	point a,b,x;
	int d,n;
	scanf("%d",&d);
	a.scan();
	b.scan();
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		x.scan();
		if(a*x>=0 && b*x<=0 && x.len2()<=d*d)
			if(a*b==0 && (a%x<=0 || b%x<=0))
				printf("NO\n");
			else
				printf("YES\n");
		else
			printf("NO\n");
	}
	system("pause");
}