#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n,m;
	cin >> n;
	short* an = new short[n];
	for(int i=0; i<n; i++)
		cin >> an[i];
	cin >> m;
	short* am = new short[m];
	for(int i=0; i<m; i++)
		cin >> am[i];
	int sum = 0;
	int j=0;
	for(int i=0; i<m && sum!=10000; i++) {
		j=0;
		sum=0;
		while(sum < 10000 && j < n) {
			sum = am[i]+an[j];
			j++;
		}
	}
	cout << endl;
	if(sum==10000)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	system("pause");
}