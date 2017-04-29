#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int n, m;
vector<  vector<int> > G;
vector<bool> used;
int main() {
    scanf("%d%d", &n, &m);
    G.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int from, to;
        scanf("%d%d", &from, &to);
        G[from-1].push_back(to-1);
    }
    used.assign(n, false);
    bool t = true;
    for(int i = 0; i < n && t; i++){
        int v;
        scanf("%d", &v);
        v--;
        if(used[v])
            t = false;
        used[v] = true;
        for(int i = 0; i < G[v].size()&& t; i++){
            if(used[G[v][i]]){
                t = false;
            }
        }
    }
    printf(t ? "YES" : "NO");
    return 0;
}