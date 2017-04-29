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

map<pair<int, int>, long long> cache;

const long long P = 1000000007;


long long A(int l, int s) {
    if (s==0) {
        return 1;
    }
    if (l==0) {
        return 0;
    }
    if (s==1) {
        return l;
    }
    long long answer = 0;
    for (int i=0; i<10 && s-i >= 0; i++) {
        if (cache.find(mp(l-1,s-i))==cache.end()) {
            long long tmp = A(l-1, s-i);
            answer+=tmp;
            cache[mp(l-1,s-i)] = tmp;
        } else {
            answer+=cache[mp(l-1,s-i)];
        }
    }
    return answer;
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
        int sum = 0;
        scanf("%d", &sum);
        long long answer = A(9, sum);
        if (sum==1) {
            answer++;
        }
        printf("%lld\n", answer);
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}