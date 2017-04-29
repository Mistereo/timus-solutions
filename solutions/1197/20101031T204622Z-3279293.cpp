#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int horse(char cx, int y) {
	int x = (int)(cx) -96;
	int v = 0;
	int z = 0;
	for (int i=0; i<2; i++) {

	if(y+2<=8 && y+2>=1 &&  x+1<=8 && x+1>=1) {
		v++;
	}
	if(y+2<=8 && y+2>=1 && x-1<=8 && x-1>=1) {
		v++;
	}
	if(y-2<=8  && y-2>=1 && x+1<=8 && x+1>=1) {
		v++;
	}
	if(y-2<=8 && y-2>=1 && x-1<=8 && x-1>=1) {
		v++;
	}
	z = x;
	x = y;
	y = z;
	}
	return v;
}
int main() {
	char cx;
	int y;
	int n;
	int v;
	cin >> n;
	string cv;
	for (int i = 0; i<n; i++) {
		cin >> cx;
		cin >> y;
		v = horse(cx,y);
		ostringstream out;
		out << v << "\n";
		cv += out.str();
	}
	cout << cv;
}