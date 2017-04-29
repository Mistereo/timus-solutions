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
using namespace std;

const int INF = 1000000000;

struct edge {
    int a, b, cost;
    bool operator<(edge b) const {
        return cost < b.cost;
    }
    void scan() {
        scanf("%d%d%d", &a, &b, &cost);
        a--;
        b--;
    }
};
int n;
int m;
int *parent;
edge *G;
void makeSet(int x) {
    parent[x] = x;
}
int findSet(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}
void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rand() & 1) swap(a, b);
        parent[b] = a;
    }
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d%d", &n, &m);
    parent = new int[n];
    G = new edge[m];
    for (int i=0; i<n; i++) parent[i] = i;
    for (int i=0; i<m; i++) G[i].scan();
    
    sort(G, G+m);
    
    int ans1 = 0;
    int count1 = 0;
    vector<int> tmp;
    for (int i=0; i<m; i++) {
        int a = G[i].a;
        int b = G[i].b;
        int cost = G[i].cost;
        if(findSet(a) != findSet(b)) {
            //printf("--%d %d\n", a, b);
            tmp.push_back(i);
            ans1+=cost;
            count1++;
            unionSets(a, b);
        }
    }
    int ans2 = INF;
    int count2 = 0;
    for (auto k = tmp.begin(); k!=tmp.end(); k++) {
        int tmp = 0;
        for (int i=0; i<n; i++) parent[i] = i;
        for (int i=0; i<m; i++) {
            if (i!=*k) {
                int a = G[i].a;
                int b = G[i].b;
                int cost = G[i].cost;
                if(findSet(a) != findSet(b)) {
                    //printf("--%d %d\n", a, b);
                    tmp+=cost;
                    count2++;
                    unionSets(a, b);
                }
            }
        }
        if (count1 == count2) ans2 = min(ans2, tmp);
        
        count2 = 0;
    }
    
    printf("Cost: %d\nCost: %d", ans1, ans2 == INF ? -1 : ans2);
    return 0;
}