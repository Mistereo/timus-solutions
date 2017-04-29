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
bool cmp(point a, point b) {
	return a.len() > b.len();
}
int main() {
	point v;
	double d=0,sum=0;
	int n;
	scanf("%d",&n);
	point* coor = new point[n];
	bool** a = new bool*[n];
	for(int i=0; i<n; i++) {
		coor[i].scan();
		a[i] = new bool[n];
		memset(a[i],0,n*sizeof(bool));
	}
	sort(coor,coor+n,cmp);
	for(int i=0; i<n; i++)
		a[i][i] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!a[i][j] && !a[j][i]) {
				a[i][j] = 1;
				a[j][i] = 1;
				//cout << "i: " << i << " " << "j: " << j << endl;
				v = coor[j]-coor[i];
				d = v.len();
				vector<int> kk;
				for(int k=0; k<n; k++) {
					if(!a[i][k] && !a[k][i] && v*(coor[k]-coor[i])==0){
						kk.push_back(k);
						//cout << "k: " << k << endl;
						a[k][j] = 1;
						a[j][k] = 1;
						a[i][k] = 1;
						a[k][i] = 1;
						d=max(d,(coor[k]-coor[i]).len());
					}
				}
				for(int x=0; x<kk.size(); x++)
					for(int k=0; k<kk.size(); k++) {
						a[kk[x]][kk[k]]=1;
						a[kk[k]][kk[x]]=1;
					}
				sum+=d;
			}
		}
	}
	cout << (int)sum;
	system("pause");
	return 0;
}