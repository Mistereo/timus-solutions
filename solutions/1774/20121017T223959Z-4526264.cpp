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
const int INF = 1000*1000*1000;


int n, s, t;

const int TMAX = 2010;

struct edge {
    int a, b;
    int cap, flow;
    edge(int a=0, int b=0, int cap=0, int flow=0):a(a),b(b),cap(cap),flow(flow){}
};

vector< vector<int> > G;
vector<int> lvl;
vector<int> ptr;
vector<edge> E;
queue<int> Q;

void addEdge(int a, int b, int cap) {
    G[a].push_back((int)E.size());
    E.push_back(edge(a,b,cap,0));
    G[b].push_back((int)E.size());
    E.push_back(edge(b,a,0  ,0));
}
bool bfs() {
    Q.push(s);
    fill(lvl.begin(), lvl.end(), -1);
    lvl[s] = 0;
    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (int i=0; i<G[v].size(); i++) {
            int id = G[v][i];
            int to = E[id].b;
            if (lvl[to] == -1 && E[id].flow < E[id].cap) {
                Q.push(to);
                lvl[to] = lvl[v] + 1;
            }
        }
    }
    return lvl[t] != -1;
}

int dfs(int v, int flow) {
    if (flow == 0) return 0;
    if (v == t) return flow;
    int resultPush = 0;
    while (ptr[v] < G[v].size()) {
        
        int id = G[v][ ptr[v] ];
        int to = E[id].b;
        
        if (lvl[to]==lvl[v]+1) {
            int pushed = dfs(to, min(flow, E[id].cap-E[id].flow));
            if (pushed) {
                E[id].flow += pushed;
                E[id^1].flow -= pushed;
                resultPush += pushed;
                flow -= pushed;
            }
        }
        
        ptr[v]++;
    }
    return resultPush;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        flow += dfs(s, INF);
    }
    return flow;
}


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,k; scanf("%d%d", &m, &k);
    
    n = TMAX+m+2;
    s = TMAX+m;
    t = TMAX+m+1;
    G.assign(n, vector<int>());
    ptr.assign(n, 0);
    lvl.assign(n, -1);
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
    return 0;
}