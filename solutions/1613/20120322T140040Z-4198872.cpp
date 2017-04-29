
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
#include <cmath>
#include <time.h>

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    map<int, vector<int> > M;
    int n; scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        M[a].push_back(i+1);
    }
    int q; scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int r,l,x; scanf("%d%d%d", &r, &l, &x);
        auto it = M.find(x);
        if (it==M.end()) {
            printf("0");
        } else {
            auto ind = lower_bound(it->second.begin(), it->second.end(), r);
            if(ind!=it->second.end() && *ind <= l) {
                printf("1");
            } else {
                printf("0");
            }
        }
    }
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}