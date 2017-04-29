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

vector< vector<int> > G;
vector<char> used;

void dfs(int v, vector< vector<int> > &G) {
    used[v] = true;
    for (int i=0; i<G[v].size(); i++) {
        if (!used[ G[v][i] ])
            dfs(G[v][i], G);
    }
}

int main() {
#ifdef MISTMAC
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    G.assign(n, vector<int>());
    used.assign(n, 0);
    
    int ans = 0;
    
    for (int i=0; i<n; i++) {
        bool x = true;
        for (int j=0; j<m; j++) {
            int color;
            scanf("%d", &color);
            color--;
            if (color!=i) {
                x = false;
                ans++;
                G[i].push_back(color);
                G[color].push_back(i);
            }
        }
        if (x)
            used[i] = true;
    }
    for (int i=0; i<n; i++) {
        if (!used[i]) {
            dfs(i, G);
            ans++;
        }
    }
    
    printf("%d", max(ans-1,0));
    
    
	return 0;
}