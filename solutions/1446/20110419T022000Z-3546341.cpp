#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
struct foo {
	string name;
	short fac;
};
int main () {
	int n;
	char c;
	string s;
	cin >> n;
	string f[] = {"Slytherin","Hufflepuff","Gryffindor","Ravenclaw"};
	foo *a = new foo[n];
	for(int i=0; i<n; i++) {
		a[i].name = "";
		cin >> c;
		while (c!='\n') {
			a[i].name+=c;
			c = cin.get();
		}
		cin >> s;
		for (int j=0; j<4; j++) {
			if(s==f[j]) {
				a[i].fac = j;
				break;
			}
		}
	}
	stable_sort(a,a+n,[](foo x, foo y){return x.fac < y.fac;});
	cout << "Slytherin:" << endl;
	int x=0;
	while (a[x].fac==0) {
		cout << a[x].name << endl;
		x++;
	}
	cout << endl << "Hufflepuff:" << endl;
	while (a[x].fac==1) {
		cout << a[x].name << endl;
		x++;
	}
	cout << endl << "Gryffindor:" << endl;
	while (a[x].fac==2) {
		cout << a[x].name << endl;
		x++;
	}
	cout << endl << "Ravenclaw:" << endl;
	while (a[x].fac==3 && x<n) {
		cout << a[x].name << endl;
		x++;
	}
	system("pause");
	return 0;
}