#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<short> d;
void foo(int n) {
	while(n%2==0){
		d.push_back(2);
		n/=2;
	}
	for(int i=3; i*i<n; i+=2)
		while(n%i==0) {
			d.push_back(i);
			n/=i;
		}
	if(n!=1)
		d.push_back(n);
}
int main () {
	int n;
	for(int i=0; i<10; i++) {
		cin >> n;
		foo(n);
	}
	sort(d.begin(),d.end());
	int s=1, c=1;
	if (d.size()!=0) {
		n=d[0];
		for(int i=1; i<d.size(); i++) {
			if(n==d[i])
				c++;
			else {
				s*=(c+1);
				c=1;
				n=d[i];
			}
		}
		if(n==d.back())
			s*=(c+1);
		cout << s%10 << endl;
	} else
		cout << 1 << endl;
	system("pause");
	return 0;
}