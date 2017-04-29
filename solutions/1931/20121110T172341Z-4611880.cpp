#define _USE_MATH_DEFINES
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define int64 long long
#define INF 100000000
#define mp make_pair

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    int *C = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", A+i);
        C[i] = 0;
    }
    int id = 0;
    for (int i=1; i<n; i++) {
        C[id]++;
        if (A[i] < A[id]) {
            id = i;
            C[id]++;
        }
    }
    int ans = (int)(max_element(C, C+n)-C)+1;
    printf("%d\n", ans);
    return 0;
}
