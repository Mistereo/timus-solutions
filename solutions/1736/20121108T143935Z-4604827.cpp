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
#define INF 100000000
#define EPS 1e-9

int s;
int t;

struct Edge {
    int a;
    int b;
    int cap;
    int flow;
    Edge(int a, int b, int cap, int flow = 0):
    a(a),
    b(b),
    cap(cap),
    flow(flow) {}
};


vector<int> ansF;
vector<int> ansA;
vector<int> ansB;
vector< vector<int> > G;
vector<Edge> E;
vector<int> ptr;
vector<int> lvl;

int addEdge(int a, int b, int cap) {
    int x = (int)E.size();
    G[a].push_back((int)E.size());
    E.push_back(Edge(a,b,cap,0));
    G[b].push_back((int)E.size());
    E.push_back(Edge(b,a,0,0));
    return x;
}

int dfs(int v, int flow) {
    if (flow == 0) return 0;
    if (v == t) return flow;
    
    int totalPush = 0;
    
    while (ptr[v] < G[v].size()) {
        int id = G[v][ ptr[v] ];
        int to = E[id].b;
        
        if (lvl[to]==lvl[v]+1) {
            int push = dfs(to, min(flow, E[id].cap - E[id].flow));
            if(push) {
                E[id].flow += push;
                E[id^1].flow -= push;
                return push;
                flow -= push;
                totalPush += push;
            }
        }
        
        ptr[v]++;
    }
    return totalPush;
}
bool bfs() {
    queue<int> Q;
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
                lvl[to] = lvl[v] + 1;
                Q.push(to);
            }
        }
    }
    return lvl[t] != -1;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    
    int games = (n*(n-1))/2;
    
    ptr.assign(n+games+2, 0);
    G.assign(n+games+2, vector<int>());
    lvl.assign(n+games+2, -1);
    G.assign(n+games+2, vector<int>());
    
    vector<int> points;
    
    s = (int)G.size()-2;
    t = (int)G.size()-1;
    
    for (int i=0; i<n; i++) {
        int k;
        scanf("%d", &k);
        points.push_back(k);
        addEdge(s, i, k);
    }
    
    sort(points.begin(), points.end());
    
    int res = points[0];
    for (int i=1; i<n; i++) {
        res+=points[i];
        if (res < 3*(i*(i+1))/2) {
            printf("INCORRECT\n");
            return 0;
        }
    }
    
    for (int i=0; i<games; i++) {
        addEdge(i+n, t, 3);
    }
    
    ansF.assign(games, 0);
    ansA.assign(games, 0);
    ansB.assign(games, 0);
    
    int ind = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ansF[ind] = addEdge(i, ind + n, 3);
            ansA[ind] = i+1;
            ansB[ind] = j+1;
            addEdge(j, ind + n, 3);
            ind++;
        }
    }
    int flow = dinic();
    if (flow == games*3) {
        printf("CORRECT\n");
        for (int i=0; i<games; i++) {
            if (E[ansF[i]].flow == 0) {
                printf("%d < %d\n", ansA[i], ansB[i]);
            }
            if (E[ansF[i]].flow == 1) {
                printf("%d <= %d\n", ansA[i], ansB[i]);
            }
            if (E[ansF[i]].flow == 2) {
                printf("%d >= %d\n", ansA[i], ansB[i]);
            }
            if (E[ansF[i]].flow == 3) {
                printf("%d > %d\n", ansA[i], ansB[i]);
            }
        }
    }
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}