#include <iostream>
#include <vector>
using namespace std;
void main () {
	vector<__int64> a;
	__int64 x;
	for(int i=0; i<3; i++) {
		cin >> x;
		a.push_back(x);
	}
	__int64 min = abs(a[0]-a[2]);
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<a.size(); j++)
			if(min>abs(a[i]-a[j]) && j!=i)
				min=abs(a[i]-a[j]);
	int count = 1;
	while(min!=0){
		count++;
		a.push_back(min);
		for(int i=0; i<a.size(); i++)
			if(min>abs(a[i]-a[a.size()-1]) && i!=a.size()-1) {
				min=abs(a[i]-a[a.size()-1]);
			}
	}
	cout << count <<endl;
	system("pause");
}