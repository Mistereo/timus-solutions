#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
const double R = 8.314;
int main() {
	char c;
	int r,p,n,v,t;
	bool bp = 0,
		bn = 0,
		bv = 0,
		bt = 0;
	for(int i = 0; i<3; i++) {
		cin >> c;
		switch (c) {
		case 'p':
			cin >> c >> p;
			bp = 1;
			break;
		case 'n':
			cin >> c >> n;
			bn = 1;
			break;
		case 'V':
			cin >> c >> v;
			bv = 1;
			break;
		case 'T':
			cin >> c >> t;
			bt = 1;
			break;
		}
	}
	if(!bp) {
		//FIND p
		printf("p = %lf \n", n*R*t/v);
	} else if(!bn) {
		//FIND n
		printf("n = %lf \n", (p*v)/(R*t));
	} else if(!bv) {
		//FIND V
		if(p==0 && n==0)
			cout << "undefined";
		else if(p==0 || n==0)
			cout << "error";
		else {
			double res = n*R*t/p;
			if (res < 0)
				cout << "error";
			else
				printf("V = %lf \n", res);
		}
	} else {
		//FIND T
		if(p==0 && n==0)
			cout << "undefined";
		else if (p==0 || n==0)
			cout << "error";
		else {
			double res = (p*v)/(R*n);
			if(res < 0)
				cout << "error";
			else
				printf("T = %lf \n", res);
		}
	}
	system("pause");
}