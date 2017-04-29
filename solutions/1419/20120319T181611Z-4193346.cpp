
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
int n,m;
vector< vector<char> > M;
vector< vector<int> > G;
int dx[] = {  0, 0,-1, 1 -1,-1, 1,1 };
int dy[] = { -1, 1, 0, 0,-1, 1,-1,1 };


vector<char> used;
int timer;
vector<int> tin, fup;

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i=0; i<G[v].size(); ++i) {
		int to = G[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
                printf("Just a picture");
                exit(0);
            }
		}
	}
}

void findBridges() {
	timer = 0;
	dfs(0);
    for (int i=0; i<used.size(); i++) {
        if (!used[i]) {
            printf("Just a picture");
            exit(0);
        }
    }
    printf("Island world");
}

inline bool isOutOfEdge(int i, int j) {
    return i>=0 && i < n && j>=0 && j<m;
}

inline bool checkDeg(int x, int y) {
    int count = 0;
    for (int i=0; i<8 && count < 4; i++) {
        int xi = x+dx[i];
        int yi = y+dy[i];
        if (isOutOfEdge(xi, yi)) {
            if (M[xi][yi]=='/' || M[xi][yi]=='-' || M[xi][yi]=='\\' || M[xi][yi]=='|') {
                count++;
            } else if(M[xi][yi]=='O') {
                return false;
            }
        }
    }
    if (count==3) {
        return true;
    }
    return false;
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    scanf("%d%d", &m, &n);
    M.assign(n,vector<char>(m));
    char c;
    scanf("%c", &c);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%c", &M[i][j]);
        }
        scanf("%c", &c);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(M[i][j]=='|') {
                if (i-1 < 0 || i+1 >= n || M[i-1][j]!='O' || M[i+1][j]!='O') {
                    printf("Just a picture");
                    exit(0);
                }
            } else if(M[i][j]=='-') {
                if (j-1 < 0 || j+1 >= m || M[i][j-1]!='O' || M[i][j+1]!='O') {
                    printf("Just a picture");
                    exit(0);
                }
            } else if(M[i][j]=='/') {
                if (j-1 < 0 || j+1 >= m || i-1 < 0 || i+1 >= n || M[i-1][j-1]!='O' || M[i+1][j+1]!='O') {
                    printf("Just a picture");
                    exit(0);
                }
            } else if(M[i][j]=='\\') {
                if (j-1 < 0 || j+1 >= m || i-1 < 0 || i+1 >= n || M[i-1][j+1]!='O' || M[i+1][j-1]!='O') {
                    printf("Just a picture");
                    exit(0);
                }
            } else if(M[i][j]!='O' && M[i][j]!=' ') {
                printf("Just a picture");
                exit(0);
            }
        }
    }
    map<pair<int, int>, int> Mp;
    int ind = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(M[i][j]=='O') {
                Mp[mp(i,j)] = ind++;
            }
        }
    }
    ind--;
    G.assign(ind+1, vector<int>());
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(M[i][j]=='|') {
                G[ Mp[mp(i-1,j)] ].push_back( Mp[mp(i+1,j)] );
                G[ Mp[mp(i+1,j)] ].push_back( Mp[mp(i-1,j)] );
            } else if(M[i][j]=='-') {
                G[ Mp[mp(i,j-1)] ].push_back( Mp[mp(i,j+1)] );
                G[ Mp[mp(i,j+1)] ].push_back( Mp[mp(i,j-1)] );
            } else if(M[i][j]=='/') {
                G[ Mp[mp(i-1,j+1)] ].push_back( Mp[mp(i+1,j-1)] );
                G[ Mp[mp(i+1,j-1)] ].push_back( Mp[mp(i-1,j+1)] );
            } else if(M[i][j]=='\\') {
                G[ Mp[mp(i+1,j+1)] ].push_back( Mp[mp(i-1,j-1)] );
                G[ Mp[mp(i-1,j-1)] ].push_back( Mp[mp(i+1,j+1)] );
            } 
        }
    }
    for (int i=0; i<G.size(); i++) {
        if (G[i].size()!=3) {
            printf("Just a picture");
            exit(0);
        }
    }
    used.assign(ind+1, 0);
    tin.assign(ind+1, 0);
    fup.assign(ind+1, 0);
    findBridges();
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}