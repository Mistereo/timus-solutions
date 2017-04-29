#include <iostream>
using namespace std;
int n;
bool **b, **a;
int count = 0;
bool add=0,add1=0;
void wave(int p, int q) {
	if(p==n-1 && q==n-1)
		add=1;
	a[p][q]=0;
	b[p+1][q+1]=0;
	if(p+1<n && a[p+1][q]) wave(p+1, q); 
	else if(b[p+2][q+1]) {
		if(p+1>=n) b[p+2][q+1]=0;
		count++;
	}
	if(p-1>-1 && a[p-1][q]) wave(p-1, q); 
	else if(b[p][q+1]) {
		if (p-1<=-1) b[p][q+1]=0;
		count++;
	}
	if(q+1<n && a[p][q+1]) wave(p, q+1); 
	else if(b[p+1][q+2]) {
		if(q+1>=n) b[p+1][q+2]=0;
		count++;	
	}
	if(q-1>-1 && a[p][q-1]) wave(p, q-1); 
	else if(b[p+1][q]) {
		if(q-1<=-1) b[p+1][q]=0;
		count++;	
	}
}
int main (void) { 
	char c;
	cin >> n;
	a = new bool*[n];
	b = new bool*[n+2];
	for(int i=0; i<n; i++) {
		b[i] = new bool[n+2];
		memset(b[i],1,n+2);
		a[i] = new bool[n];
		for(int j=0; j<n; j++) {
			cin >> c;
			if(c=='.')
				a[i][j]=1;
			else
				a[i][j]=0;
		}
	}
	if(!a[n-2][n-1])
		add1=1;
	b[n] = new bool[n+2];
	b[n+1] = new bool[n+2];
	memset(b[n],1,n+2);
	memset(b[n+1],1,n+2);
	wave(0,0);
	if(add && add1)
		count--;
	wave(n-1,n-1);
	cout << (count-4)*9;
	system("pause");
	return 0;
}