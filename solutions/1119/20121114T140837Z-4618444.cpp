#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short
#define INF 1000000000

using namespace std;

typedef pair<int, int> pii;

int n, m;
double **M;
set<pii> S;
int dx[] = { -1,  0 };
int dy[] = {  0, -1 };
int dd[] = { 100, 100 };


inline bool isValid(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < m);
}

double dist(int x, int y, int t) {
    double mn = INF;
    for (int i=0; i<2; i++) {
        if (isValid(x+dx[i], y+dy[i])) {
            mn = min(mn, M[ x+dx[i] ][ y+dy[i] ] + dd[i]);
        }
    }
    if (S.find(mp(t, y))!=S.end()) {
        double di = M[x-1][y-1];
        mn = min(mn, M[x-1][y-1]+100*sqrt(2.0));
    }
    return mn;
}

int main (int argc, const char * argv[])
{
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d%d", &m, &n);
    n++; m++;
    M = new double*[2];
    for (int i=0; i<2; i++) {
        M[i] = new double[m];
        for (int j=0; j<m; j++) {
            M[i][j] = INF;
        }
    }
    M[0][0] = 0;
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        S.insert(mp(b,a));
    }
    for (int i=1; i<m; i++) {
        M[0][i] = M[0][i-1] + 100;
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            M[1][j] = dist(1, j, i);
        }
        for (int j=0; j<m; j++) {
            M[0][j] = M[1][j];
        }
    }
    printf("%.0lf", M[0][m-1]);
    return 0;
}