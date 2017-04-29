#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int counter(int n,int k){
	if(n==0)
		return 1;
	else if (n==1)
		return k-1;
	else
		return (k-1)*counter(n-1,k) + (k-1)*counter(n-2,k);
}
int main(){
	int n,k;
	cin >> n >> k;
	cout << counter(n,k);
	system("pause");
}