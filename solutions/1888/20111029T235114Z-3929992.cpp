#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

const int INF = 1000000000;
int M[50][50];
int usedVer = 0;
bool isReversed = false;
vector<vector<int> > G;
vector<bool> used;
vector<int> colors;

void bfs(int v, int currentColor) {
    queue<int> q;
    q.push(v);
    used[v] = true;
    usedVer++;
    colors[v] = currentColor;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int i=0; i<G[v].size(); i++) {
            int to = G[v][i];
            if (!used[to]) {
                used[to] = true;
                usedVer++;
                q.push(to);
                colors[to] = colors[v] + (isReversed ? -1 : 1);
            } else if (abs(colors[v]-colors[to])!=1) {
                printf("-1");
                exit(0);
            }
        }
    }
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    
    used.assign(p, 0);
    colors.assign(p, 1);
    G.assign(p, vector<int>());
    for (int i=0; i<p; i++) {
        fill(M[i], M[i]+p, INF);
        M[i][i] = 0;
    }
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        if (M[a-1][b-1] == INF) {
            M[a-1][b-1] = 1;
            M[b-1][a-1] = 1;
            
            G[a-1].push_back(b-1);
            G[b-1].push_back(a-1);
        }
    }
    
    for (int k=0; k<p; k++)
        for (int i=0; i<p; i++)
            for (int j=0; j<p; j++)
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
    
    int mx = -1, a, b;
    for (int i=0; i<p; i++) {
        for (int j=0; j<p; j++) {
            if (M[i][j]!=INF && mx < M[i][j]) {
                mx = M[i][j];
                a = i;
                b = j;
            }
        }
    }
    bool x = false;
    bfs(a, 1);
    usedVer = 0;
    isReversed = true;
    for (int i=0; i<p; i++) {
        if (!used[i]) {
            bfs(i, 50);
            x = true;
        }
    }
    
    if (x) {
        printf("49\n");
    } else {
        printf("%d\n", mx);
    }
    for (int i=0; i<colors.size(); i++) printf("%d ", colors[i]);
    
    return 0;
}