#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
std::map<int,int> m;
using namespace std;
int counter(int n,int k){
	if(n==0)
		return 1;
	else if (n==1)
		return k-1;
	else {
		int s1,s2;
		if(m.find(n-1)!=m.end()) {
			s1=m[n-1];
		} else {
			s1=counter(n-1,k);
			m[n-1]=s1;
		}
		if(m.find(n-2)!=m.end()) {
			s2=m[n-2];
		} else {
			s2=counter(n-2,k);
			m[n-2]=s2;
		}
		return (k-1)*s1 + (k-1)*s2;
		//return (k-1)*counter(n-1,k) + (k-1)*counter(n-2,k);
	}
}
int main(){
	int n,k;
	cin >> n >> k;
	cout << counter(n,k);
	system("pause");
}