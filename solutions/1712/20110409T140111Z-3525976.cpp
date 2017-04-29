#include <iostream>
#include <algorithm>
using namespace std;
bool a[4][4];
char ac[4][4];
char c;
void transform() {
	bool x[4][4];
	int k=0, l=0;
	for(int i=3; i>=0; i--) {
		l=0;
		for(int j=0; j<4; j++) {
			x[j][i]=a[k][l];
			l++;
		}
		k++;
	}
	swap(a,x);
}
int main() {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			cin >> c;
			if(c=='X')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			cin >> ac[i][j];
		}
	}
	for(int k=0; k<4; k++) {
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				if(a[i][j])
					printf("%c",ac[i][j]);
			}
		}
		transform();
	}
	system("pause");
}