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

int n = 0,k = 0;

vector<char> used;
vector<int> mt;
vector< vector<int> > G;

bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int i=0; i<G[v].size(); i++) {
        int to = G[v][i];
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}


int main (int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n,k,m; scanf("%d%d%d", &n, &k, &m);
    
    G.assign(n, vector<int>());
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a,&b);
        G[a-1].push_back(b-1);
    }
    
    mt.assign(k, -1);
    
    vector<char> used1(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<G[i].size(); j++) {
            if (mt[ G[i][j] ] == -1) {
                mt[ G[i][j] ] = i;
                used1[i] = true;
                break;
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (used1[i]) continue;
        used.assign(n, false);
        kuhn(i);
    }
    
    int p = 0;
    for (int i=0; i<k; i++) {
        if (mt[i] != -1) {
            p++;
        }
    }
    
    printf("%d", n+k-p);
    
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}