#include <stack>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
	long long n, a = 1, p=0, tmpA;
	cin >> n;
	for(long long i=(long long)(sqrt(double(2*n))); i>0; i--) {
		tmpA = (2*n - i * i + i)/(2*i);
		if(n == i*tmpA + (i*(i-1))/2 && tmpA > 0) {
			p = i;
			a = tmpA;
			break;
		}
	}
	cout << endl << a << " " << p << endl;
	system("pause");
	return 0;
}