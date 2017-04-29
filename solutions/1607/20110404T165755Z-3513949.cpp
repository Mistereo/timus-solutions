#include <iostream>
//(c) Michael Plusnin & Mistereo
using namespace std;

int main(){
	int p,pi,d,di;
	cin >> p >> pi >> d >> di;
	bool asd = 1;
	while(p!=d && p<d) {

		if(p+pi < d && asd) {
			p+=pi;
		}
		else if(p+pi >= d && asd) {
			p=d;
		}

		//////////////////////////////////
		
		if(d-di > p && !asd) {
			d-=di;
		}
		else if(d-di <= p && !asd)
			d=p;
		asd = !asd;
	}
	cout << p << endl;
	system("pause");
	return 0;
}