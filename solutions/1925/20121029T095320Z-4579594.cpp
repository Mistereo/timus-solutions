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
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    int A = k;
    int B = 2;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        A+=a;
        B+=b;
    }
    int ans = A-B-n*2;
    if (ans >= 0) {
        printf("%d\n", ans);
    } else {
        printf("Big Bang!\n");
    }
	return 0;
}