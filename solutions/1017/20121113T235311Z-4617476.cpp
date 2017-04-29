#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

#define int64 long long

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    n++;
    int64 **dp = new int64*[n];
    for(int i=0; i<n; i++) {
        dp[i] = new int64[n];
        for (int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }
    
    for (int i=0; i<n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
        dp[i][i] = 1;
    }
    
    for (int i=1; i<n; i++) {
        for (int j=1; j<i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-j][j-1];
        }
    }
    int64 res = 0;
    for (int i=0; i<n; i++) {
        res += dp[n-1][i];
    }
    printf("%lld", res - 1);
    return 0;
}