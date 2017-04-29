#include <iostream>
using namespace std;
void main(){
	int n;
	cin >> n;
	int a[100][100];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}

	for(int i=0; i<2*n; i++){
		for(int j=0; j<i+1 && j<n; j++){
			if(i-j<n)
				cout << a[i-j][j] << " ";
		}
	}

	system("pause");
}