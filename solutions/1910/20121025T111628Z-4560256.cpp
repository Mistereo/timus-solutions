#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 1000000000


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    for (int i=0; i<n; i++)
        scanf("%d", A+i);
    int sum = A[0]+A[1]+A[2];
    int ID = 0;
    for (int i=1; i<n-2; i++) {
        int S = A[i]+A[i+1]+A[i+2];
        if (S > sum) {
            sum = S;
            ID = i;
        }
    }
    printf("%d %d\n", sum, ID+2);
    return 0;
}