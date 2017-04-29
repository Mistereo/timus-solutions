#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct student {
	int t1,t2,t3;
	student(int t1=0, int t2=0, int t3=0):t1(t1),t2(t2),t3(t3){};
	void scan(){
		scanf("%d%d%d",&t1,&t2,&t3);
	}
};
int main() {
	int n,x=0,mx=0;
	scanf("%d",&n);
	student *a = new student[n];
	for (int i=0; i<n; i++)
		a[i].scan();
	sort(a,a+n,[](student a, student b) {return a.t1 < b.t1;});
	for (int i=0; i<n; i++) {
		if(x > a[i].t1)
			a[i].t1 = x;
		x = a[i].t1+a[i].t2;
		if (x>a[i].t3)
			mx = max(mx, x-a[i].t3);
	}
	printf("%d\n",mx);
	system("pause");
	return 0;
}