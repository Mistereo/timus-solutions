#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, out, x;
	scanf("%d%d",&n,&out);
	int left=-1000,right=1000;
	for (int i=0; i<n; i++) {
		scanf("%d",&x);
		if (x < 0)
			left = max(left,x);
		else
			right = min(right,x);
	}
	if(out < right && out > left)
		if(out < 0)
			printf("%d %d", right*2-out, -out);
		else
			printf("%d %d", out, -left*2+out);
	else 
		printf("Impossible");
	system("pause");
	return 0;
}