#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class point {
	__int64 x, y;
public:
	point(__int64 x = 0, __int64 y = 0) : x(x), y(y) {};
	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	point operator-(point a) {
		return point(x - a.x, y - a.y);
	}
	__int64 operator*(point a) {
		return x * a.y - y * a.x;
	}
};
int main() {
	int n,c;
	scanf("%d",&n);
	point *arr = new point[n];
	for(int i=0; i<n; i++)
		arr[i].scan();
	for(int i=1; i<n; i++) {
		c=0;
		for(int j=1; j<n; j++) {
			if((arr[i]-arr[0])*(arr[j]-arr[0]) > 0)
				c++;
			else
				c--;
		}
		if(c==-1) {
			printf("1 %d\n",i+1);
			break;
		}
	}
	system("pause");
	return 0;
}