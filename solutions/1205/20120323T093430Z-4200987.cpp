
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

long double dist(pair<long double, long double> a, pair<long double, long double> b) {
    auto x = mp(a.first-b.first, a.second-b.second);
    return sqrt(x.first*x.first+x.second*x.second);
}
int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    long double manSpeed, metroSpeed; scanf("%Lf%Lf", &manSpeed, &metroSpeed);
    int n; scanf("%d", &n);

    
    vector< pair<long double, long double> > Stations;
    for (int i=0; i<n; i++) {
        long double a, b; scanf("%Lf%Lf", &a, &b);
        Stations.push_back(mp(a,b));
    }
    int m = n+2;
    vector< vector< pair<int, long double> > > G(m);
    int a,b;
    scanf("%d%d", &a, &b);
    while (a!=0 || b!=0) {
        long double cost = dist(Stations[a-1], Stations[b-1]) / metroSpeed;
        G[a-1].push_back(mp(b-1, cost));
        G[b-1].push_back(mp(a-1, cost));
        scanf("%d%d", &a, &b);
    }
    
    int s = m-2;
    int t = m-1;
    long double aa, bb;
    scanf("%Lf%Lf", &aa, &bb);
    pair<long double, long double> A = mp(aa,bb);
    scanf("%Lf%Lf", &aa, &bb);
    pair<long double, long double> B = mp(aa,bb);
    
    G[s].push_back(mp(t,dist(A, B)/manSpeed));
    
    for (int i=0; i<n; i++) {
        long double cost = dist(Stations[i], A) / manSpeed;
        G[s].push_back(mp(i, cost));
        cost = dist(Stations[i], B) / manSpeed;
        G[i].push_back(mp(t, cost));
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            long double cost = dist(Stations[i], Stations[j]) / manSpeed;
            G[i].push_back(mp(j,cost));
            G[j].push_back(mp(i,cost));
        }
    }
    vector<long double> d(m,INF);
    d[s] = 0;
    vector<int> id(m);
    deque<int> q;
    q.push_back(s);
    vector<int> p(m, -1);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        id[v] = 1;
        for (int i=0; i<G[v].size(); i++) {
            int to = G[v][i].first;
            long double cost = G[v][i].second;
            if (d[to] > d[v] + cost) {
                d[to] = d[v] + cost;
                p[to] = v;
                if (id[to]==0) {
                    q.push_back(to);
                } else if (id[to]==1) {
                    q.push_front(to);
                }
                id[to] = 1;
            }
        }
    }
    printf("%.10Lf\n", d[t]);
    vector<int> Answer;
    for (int v=t; v!=s; v=p[v]) {
        if (v<m-2) {
            Answer.push_back(v);
        }
    }
    reverse(Answer.begin(), Answer.end());
    printf("%d ", int(Answer.size()));
    for (int i=0; i<Answer.size(); i++) {
        printf("%d ", Answer[i]+1);
    }
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}