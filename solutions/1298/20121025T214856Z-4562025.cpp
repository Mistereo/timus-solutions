#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 2000000000
#define EPS 1e-9
int n;
int **A;
int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[] = {1, -1, 2, 2, -1, 1, -2, -2};

bool valid(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < n && A[x][y]==0)
        return true;
    return false;
}

int cnt(int x, int y) {
    int cnt = 0;
    for (int i=0; i<8; i++) {
        if(valid(x+dx[i], y+dy[i]) && A[ x+dx[i] ][ y+dy[i] ] == 0)
            cnt++;
    }
    return cnt;
}

pair<int, int> move(int x, int y) {
    int mn = INF;
    pair<int, int> move = make_pair(INF, INF);
    for (int i=0; i<8; i++) {
        if (valid(x+dx[i], y+dy[i])) {
            int cur = cnt(x+dx[i], y+dy[i]);
            if (cur < mn) {
                mn = cur;
                move.first = x+dx[i];
                move.second = y+dy[i];
            }
        }
    }
    return move;
}


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    A = new int*[n];
    for (int i=0; i<n; i++) {
        A[i] = new int[n];
        for (int j=0; j<n; j++) {
            A[i][j] = 0;
        }
    }
    A[0][0] = 1;
    int id = 2;

    pair<int, int> lst = make_pair(0, 0);
    vector< pair<int, int> > ans;
    ans.push_back(make_pair(0,0));
    for (int i=0; i<n*n-1; i++) {
        pair<int, int> x = move(lst.first, lst.second);
        if (x.first == INF) {
            printf("IMPOSSIBLE\n");
            exit(0);
        }
        A[x.first][x.second] = id++;
        ans.push_back(make_pair(x.first, x.second));
        lst = x;
    }
    for (int i=0; i<ans.size(); i++) {
        printf("%c%d\n", ans[i].first+'a', ans[i].second+1);
    }
    
    return 0;
}