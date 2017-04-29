#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){
	int x,max;
	int a[100000];
	a[0]=0;
	a[1]=1;
	for(int i=2; i<100000; i++) {
		if(i%2==0)
			a[i] = a[i/2];
		else
			a[i] = a[i/2] + a[i/2+1];
	}
	cin >> x;
	while(x!=0){
		max=0;
		for(int i=0; i<=x; i++)
			if(a[i]>max)
				max=a[i];
		cout << max << endl;
		cin >> x;
	}
	cout << endl;
	system("pause");
}