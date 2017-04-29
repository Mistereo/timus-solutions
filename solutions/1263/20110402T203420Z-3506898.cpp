#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){
	int n,m,p;
	cin >> n >> m;
	int a[10000] = {0};
	for(int i=0; i<m; i++) {
		cin >> p;
		a[p-1]++;
	}
	for(int i=0; i<n; i++) {
		double res = (double)a[i]*100/m;
		printf("%.*lf%% \n",2, res);
	}
	cout << endl;
	system("pause");
}