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
    int ans = 0;
    int mx = -1;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        ans += a;
        mx = max(mx,a);
    }
    printf("%d\n", ans+mx);
    return 0;
}
