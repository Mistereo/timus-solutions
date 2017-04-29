#define _USE_MATH_DEFINES
#include <map>
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
#define mp make_pair
#define pb push_back
#define int64 long long

#define EPS 1e-9

#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)

vector< vector< pair<int, int> > > G;
vector<int> used;

int dfs(int v, double p) {
    used[v]=true;
    int res = 0;
    vector<int> D;
    for (int i=0; i<G[v].size(); i++) {
        int to = G[v][i].second;
        if (!used[ to ]) {
            D.push_back(G[v][i].first+dfs(to, p));
        }
    }
    sort(D.begin(), D.end());
    int mx = (int)ceil(G[v].size()*p);
    
    for (int i=0; i<mx; i++)
        res = max(res, D[i]);
    return res;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n, d;
    scanf("%d%d", &n, &d);
    
    G.assign(n, vector<  pair<int, int> >());
    used.assign(n, 0);
    
    for (int i=1; i<n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a-1].push_back(mp(b, i));
    }
    
    double l = 0;
    double r = 1;
    
    while (r-l > EPS) {
        double m = (r+l)/2;
        int days = dfs(0, m);
        if (days <= d) {
            l = m;
        } else {
            r = m;
        }
        fill(used.begin(), used.end(), 0);
    }
    
    printf("%.9lf", r*100);
    
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}