#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 101
void main(){
	int g[N],b[N];
	int n,m,z,
		min = 0,
		gc = 0,
		bc = 0,
		k = 1;
	cin >> n >> m;
	if(n==m){
		cout << 0;
	} else {
		for(int i=0; i<n; i++) {
			cin >> g[i];
			min+=g[i];
		}
		for(int i=0; i<m; i++) {
			cin >> b[i];
		}
		bool x = true;
		while(x){
			x=false;
			for(int i=0; i<n-1; i++)
				if(g[i]<g[i+1]){
					z = g[i];
					g[i] = g[i+1];
					g[i+1] = z;
					x = true;
				}
		}
		x = true;
		while(x){
			x=false;
			for(int i=0; i<m-1; i++)
				if(b[i]<b[i+1]){
					z = b[i];
					b[i] = b[i+1];
					b[i+1] = z;
					x = true;
				}
		}
		for(int i=0; i<n && i<m; i++){
			gc=0;
			bc=0;
			k=i+1;
			for(int j=i+1; j<n; j++) {
				gc+=g[j];
			}
			for(int j=i+1; j<m; j++) {
				bc+=k*b[j];
			}
			if(min>=gc+bc){
				min = gc+bc;
			}
		}
		cout << min;
	}
	system("pause");
}