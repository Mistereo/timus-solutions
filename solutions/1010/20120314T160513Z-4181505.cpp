
#ifndef ONLINE_JUDGE
#include <ctime>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <sstream>

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;

long long abc(long long a) {
    return a >= 0 ? a : -a;
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n;
    scanf("%d", &n);
    
    long long ans1 = 1, ans2 = 2, mx = 0;
    long long a; scanf("%lld", &a);
    for(int i=1; i<n; i++) {
        long long b; 
        scanf("%lld", &b);
        if (abc(a-b) > mx) {
            mx = abc(a-b);
            ans1 = i;
            ans2 = i+1;
        }
        a = b;
    }
    
    printf("%lld %lld\n", ans1, ans2);
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}