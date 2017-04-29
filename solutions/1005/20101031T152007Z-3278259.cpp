#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int comb(int n, int k, int sum, int array[])
{
	vector<int> mask(k, 0);
	mask.resize(n, 1);
	int min=sum;
	do
	{
		int x=0;
		for (int i=0; i < mask.size(); i++){
			if (!mask[i]) {
				x+=array[i];
			}
		}
		if(abs(sum-x-x)<min) {
			min=abs(sum-x-x);
		}
	} while (next_permutation(mask.begin(), mask.end()));
	return min;
}

void main () {
	int n; 
	cin >> n;
	int *a = new int[n];
	int sum=0, k=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		sum+=a[i];
	}
	k = n/2;
	int temp = 0;
	int min = sum;
	for (int i=1; i<=n/2; i++) {
		temp = comb(n,i,sum,a);
		if (temp < min)
			min=temp;
	}
	cout << min << endl;
	system("pause");
}