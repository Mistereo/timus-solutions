#include <iostream>
#include <set>
using namespace std;
int *T;
void build(int a[], int v, int t1, int tr) {
    if (t1 == tr) {
        T[v] = a[t1];
    } else {
        int tm = (t1 + tr) / 2;
        build(a, v*2, t1, tm);
        build(a, v*2+1, tm+1, tr);
        T[v] = T[v*2] + T[v*2+1];
    }
}
int sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return T[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm))
    + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
int main() {
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    T = new int[4*n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    build(A, 1, 0, n-1);
    int nn;
    scanf("%d", &nn);
    for (int i=0; i<nn; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", sum(1, 0, n-1, a-1, b-1));
    }
    return 0;
}