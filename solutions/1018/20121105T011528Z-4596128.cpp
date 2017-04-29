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
#include <map>
using namespace std;
#define INF 1000000000
#define int64 long long
#define mp make_pair

#define N 1000500
#define P 1000000007
#define V first
#define COST second

int n, k;
int timer = 0;

vector< vector< pair<int, int> > > tG;
vector< vector< pair<int, int> > > G;
vector<int> T;
vector< vector<int> > H;
void makeTree(int v) {
    T[v] = timer++;
    for (int i=0; i<tG[v].size(); i++) {
        int to = tG[v][i].V;
        if (T[to] == -1) {
            makeTree(to);
            G[ T[v] ].push_back( mp(T[to],
                                    tG[v][i].COST) );
        }
    }
}

int cost(int from, int to) {
    if (from == -1)
        return 0;
    return G[from][to].COST;
}

int dfs(int v, int d, int cost) {
    if (d==-1) return 0;
    if (d == 0) return cost;
    if (G[v].size() == 0) return cost;
    //printf("%d %d %d\n", v, d, cost);
    if (H[ v ][ d ]!=-1) return H[ v ][ d ];
    
    int res = 0;
    
    for (int i=0; i<=d; i++) {
        int a = dfs(G[v][0].V, i-1, G[v][0].COST);
        int b = dfs(G[v][1].V, d-i-1, G[v][1].COST);
        
        
        
        int tmpRes = a+b;
        
        res = max(res, tmpRes);
    }
    H[ v ][ d ] = res + cost;
    return res + cost;
}

int main() {
#ifdef MISTMAC
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    scanf("%d%d", &n, &k);
    
    T.assign(n, -1);
    G.assign(n, vector< pair<int, int> >());
    tG.assign(n, vector< pair<int, int> >());
    H.assign(n, vector<int>(k+k, -1));
    for (int i=0; i<n-1; i++) {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        tG[a].push_back(mp(b,c));
        tG[b].push_back(mp(a,c));
    }
    makeTree(0);
    printf("%d\n", dfs(0, k, 0));
    
	return 0;
}