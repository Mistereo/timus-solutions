#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	float r;
	float PI = 3.14159265358979323846f;
	cin >> n >> r;
	float sum = 0;
	if (n==1){
		sum = 2*PI*r; 
		printf("%.2f", sum);
		return 0;
	}
	float x1,x2,y1,y2,xfirst,yfirst;
	for (int i=0; i<n-1; i++) {
		if(i==0) {
			cin >> x1 >> y1 >> x2 >> y2;
			xfirst =x1;
			yfirst = y1;
		}
		else {
			x1 = x2;
			y1 = y2;
			cin >> x2 >> y2;
		}
		sum += sqrt(pow((x1-x2),2)+pow((y1-y2),2));
	}
	sum += (2* PI * r) + sqrt(pow((x2-xfirst),2)+pow((y2-yfirst),2));
	printf("%.2f", sum);
	system("pause");
	return 0;
}