#include <iostream>
using namespace std;
#define N 165000
int main()
{
	bool a[N];
	int pr[15001];
	memset(a,true,N);
	memset(a,false,2);
	for(int i=2; i*i<N; i++)
		if(a[i])
			for(int j=i*i; j<N; j+=i)
				a[j] = false;
	int k=1;
	for(int i=2; i<N; i++)
		if(a[i]) {
			pr[k]=i;
			k++;
			if(k==15001)
				break;
		}
	int n,x,count;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		cout << pr[x] << endl;
	}
	system("pause");
}