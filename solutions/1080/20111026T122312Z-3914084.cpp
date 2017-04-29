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
const int INF = 1000000000;
int n, m;
enum type {
    UNUSED = 0,
    RED = 1,
    BLUE = 2
};
vector<type> used;
vector<vector<int> > G;
bool x = true;
void dfs(int v, type color = RED) {
    //printf("%d ", v);
    if (used[v] == UNUSED) {
        used[v] = color;
    } else if (used[v]!=color) {
        x = false;
        return;
    }
    for (int i=0; i<G[v].size(); i++) {
        if (used[G[v][i]] == UNUSED) {
            dfs(G[v][i], (color == RED ? BLUE : RED));
        } else if (used[G[v][i]]==color) {
            x = false;
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    G.assign(n, vector<int>());
    used.assign(n, UNUSED);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        while (x) {
            G[i].push_back(x-1);
            G[x-1].push_back(i);
            scanf("%d", &x);
        }
    }
    dfs(0);
    if (x) {
        for (int i=0; i<n; i++) {
            printf("%d", used[i]-1);
        }
    } else {
        printf("-1");
    }
    
    return 0;
}