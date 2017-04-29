#include <iostream>
#define N 6
using namespace std;

void main () {
	int n,count,x,y;
	cin >> n;
	count=1;
	cin >> x;
	for(int i=0; i<n-1; i++){
		cin >> y;
		if(x==y)
			count++;
		else {
			cout << count <<" " << x << " ";
			x=y;
			count=1;
		}
	}
	cout << count <<" " << x << " ";
	//**************
	cout << endl;
	system("pause");
}