#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef vector<int> lnum;
const int base = 1000*1000*1000;
char buffer [33];
std::map<int,lnum> m;
void printer(lnum a){
	printf ("%d",a.empty() ? 0 : a.back());
	for (int i = (int)a.size()-2; i>=0; i--)
		printf("%09d",a[i]);
}
void sum(lnum &a, lnum &b) {
	int carry = 0;
	for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= base;
		if (carry)  a[i] -= base;
	}
}
void multi(lnum &a, int b) {
	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		long long cur = carry + a[i] * 1ll * b;
		a[i] = int (cur % base);
		carry = int (cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
}
void read(lnum &a, string s){
	for (int i=(int)s.length(); i>0; i-=9)
		if (i < 9)
			a.push_back (atoi (s.substr(0, i).c_str()));
		else
			a.push_back (atoi (s.substr(i-9, 9).c_str()));
}
void read(lnum &a){
	for (int i=(int)strlen(buffer); i>0; i-=9) {
		buffer[i] = 0;
		a.push_back (atoi (i>=9 ? buffer+i-9 : buffer));
	}
}
using namespace std;
lnum counter(int n,int k){
	lnum s1;
	if(n==0) {
		read(s1,"1");
		return s1;
	}
	else if (n==1) {
		_itoa((k-1),buffer,10);
		read(s1);
		return s1;
	}
	else {
		lnum s2;
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
		multi(s1,(k-1));
		multi(s2,(k-1));
		sum(s1,s2);
		return s1;
		//return (k-1)*counter(n-1,k) + (k-1)*counter(n-2,k);
	}
}
int main() {
	int n,k;
	cin >> n >> k;
	printer(counter(n,k));
	system("pause");
}