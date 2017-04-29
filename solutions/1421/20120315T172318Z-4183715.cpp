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
const int MAXN = 400;
const int INF = 1000*1000*1000;

queue<int> q;
int n;
int ptr[MAXN];
int c[MAXN][MAXN];
int f[MAXN][MAXN];
int d[MAXN];
int s,t;

bool bfs() {
    q.push(s);
    fill(d, d+MAXN, -1);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to=0; to<n; to++) {
            if (d[to] == -1 && f[v][to] < c[v][to] ) {
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow) {
    if (v==t || flow==0) return flow;
    
    for (int &to = ptr[v]; to<n; to++) {
        if (d[to] != d[v]+1) continue;
        
        int pushed = dfs(to, min(flow, c[v][to] - f[v][to]));
        if (pushed) {
            f[v][to] += pushed;
            f[to][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(ptr, ptr+MAXN, 0);
        while ( int pushed = dfs(s, INF) ) flow += pushed;
    }
    return flow;
}

int main (int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    scanf("%d", &n);
    int bank[MAXN], firm[MAXN];
    int sum = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &firm[i]);
        sum += firm[i];
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &bank[i]);
    }
    s = 2*n; t = 2*n+1;
    for (int i=0; i<n; i++) {
        c[s][i] = firm[i];
    }
    for (int i=0; i<n; i++) {
        c[i+n][t] = bank[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j+n] = 100;
        }
    }

    int m = n;
    n = 2*n+2;
    int flow = dinic();
    
    if (flow == sum) {
        printf("YES\n");
    } else {
        printf("NO");
        exit(0);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            printf("%d ", f[i][j+m]);
        }
        printf("\n");
    }
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}