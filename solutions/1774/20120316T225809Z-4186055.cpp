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


const int TMAX = 2010;
const int INF = 1000*1000*1000;

struct Edge {
    int a, b, cap, flow;
};
int n,k,s,t;

vector< vector<int> >G;
vector<Edge> E;
vector<int> ptr;
vector<int> d;
queue<int> q;

void addEdge(int a, int b, int cap) {
    Edge e1 = {a,b,cap,0};
    Edge e2 = {b,a,0,0};
    G[a].push_back(int(E.size()));
    E.push_back(e1);
    
    G[b].push_back(int(E.size()));
    E.push_back(e2);
}

bool bfs() {
    q.push(s);
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i=0; i<G[v].size(); i++) {
            int id = G[v][i];
            int to = E[id].b;
            if (d[to] == -1 && E[id].flow < E[id].cap) {
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs(int v, int flow) {
    if (flow==0) return 0;
    if (v==t) return flow;
    while (ptr[v]<int(G[v].size())) {
        int id = G[v][ ptr[v] ];
        int to = E[id].b;
        
        if (d[to]!=d[v]+1) { 
            ptr[v]++;
            continue;
        }
        int pushed = dfs(to, min(flow, E[id].cap-E[id].flow));
        if (pushed) {
            E[id].flow += pushed;
            E[id^1].flow -= pushed;
            return pushed;
        }
        
        ptr[v]++;
    }
    return 0;
}
int dinic() {
    int flow = 0;
    while (bfs()) {
        //ptr.assign(n, 0);
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, INF)) {
            flow += pushed;
        }
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
    int m,k; scanf("%d%d", &m, &k);
    
    n = TMAX+m+2;
    s = TMAX+m;
    t = TMAX+m+1;
    G.assign(n, vector<int>());
    ptr.assign(n, 0);
    d.assign(n, -1);
    vector< pair<int, int> > Times(m,mp(-1,-1));
    

    for (int i=0; i<m; i++) {
        int ti, si; scanf("%d%d", &ti, &si);
        for (int j=ti; j<ti+si; j++) {
            addEdge(j, TMAX+i, 1);
        }
        addEdge(TMAX+i, t, 2);
    }
    for (int i=0; i<TMAX; i++) {
        addEdge(s, i, k);
    }
    
    
    int flow = dinic();
    if (flow!=m*2) {
        printf("No\n");
        exit(0);
    }
    printf("Yes\n");
    
    for (int i=0; i<E.size(); i+=2) {
        int to = E[i].b;
        if(E[i].flow != 0 && (E[i].b >= TMAX && E[i].b<n-2)) {
            if (Times[to-TMAX].first == -1) {
                Times[to-TMAX].first = E[i].a;
            } else {
                Times[to-TMAX].second = E[i].a;
            }
        }
    }
    
    for (int i=0; i<Times.size(); i++) {
        printf("%d %d\n", min(Times[i].first, Times[i].second), max(Times[i].first, Times[i].second) );
    }
    
    //for (int i=0; i<n; i++) {
    //    printf("(%d, %d) %d %d\n", E[i].a, E[i].b, E[i].cap, E[i].flow);
    //}
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}