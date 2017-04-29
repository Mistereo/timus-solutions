#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		long a,b;
		cin >> a >> b;
		if (a==b)
			cout << "1" << endl;
		else if (b % a != 0)
			cout << "0" << endl;
		else {
			int count=2;
			int div=2;
			b/=a;
			while (a!=b) {
				div=2;
				while (b%div!=0) {
					div++;
					if(div*div>b)
						break;
				}
				if(div*div>b)
						break;
				b=b/div;
				if (b==1){
					break;
				}
				count++;
			}
			cout << count << endl;
		}
	}
	system("pause");
	return 0;
}