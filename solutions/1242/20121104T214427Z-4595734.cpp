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
vector< vector<int> > invG;
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
    
    int n;
    
    scanf("%d", &n);
    
    G.assign(n, vector<int>());
    invG.assign(n, vector<int>());
    used.assign(n, 0);

    char str[100];
    gets(str);
    while (true) {
        gets(str);
        if (str[0]=='B') {
            break;
        }
        int a, b;
        sscanf(str, "%d %d", &a, &b);
        a--; b--;
        G[a].push_back(b);
        invG[b].push_back(a);
    }
    
    while (scanf("%d", &n)!=EOF) {
        dfs(n-1, G);
        dfs(n-1, invG);
    }
    bool x = true;
    for (int i=0; i<used.size(); i++) {
        if (!used[i]) {
            printf("%d ", i+1);
            x = false;
        }
    }
    if (x) {
        printf("0\n");
    }
	return 0;
}