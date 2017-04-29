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

vector<vector<bool> >usedMap;
vector<vector<char > > M;
vector<vector<int> > d;
map<char, vector< pair<int, int> > > T;
vector<vector<bool> >used(n);
deque<pair<int, int> > q;


const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >=n || y >= m) {
        return false;
    }
    return true;
}

void wave(int xxx, int yyy) {
    
    
    q.push_back(make_pair(xxx, yyy));
    used[xxx][yyy] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        
        for (int i=0; i<8; i++) {
            int nextX = x+dx[i];
            int nextY = y+dy[i];
            if (isValid(nextX, nextY)) {
                if (!used[nextX][nextY]) {
                    used[nextX][nextY] = true;
                    if (isalpha(M[nextX][nextY])) {
                        q.push_back(make_pair(nextX, nextY));
                        d[nextX][nextY] = d[x][y] + 1;
                        for (vector<pair<int, int> >::iterator it = T[M[nextX][nextY]].begin(); it!=T[M[nextX][nextY]].end(); it++) {
                            if (!used[it->first][it->second]) {
                                used[it->first][it->second] = true;
                                q.push_back(make_pair(it->first,it->second));
                                d[it->first][it->second] = d[x][y] + 1;
                            }
                        }
                    } else {
                        q.push_back(make_pair(nextX, nextY));
                        d[nextX][nextY] = d[x][y] + 1;
                    }
                }
            }
        }
    }
}
int main() {
    
    scanf("%d%d", &n, &m);
    
    M.assign(n, vector<char>(m));
    usedMap.assign(n, vector<bool>(m,0));
    d.assign(n, vector<int>(m,0));
    
    int ax, ay, bx, by, sx, sy;
    for (int i=0; i<n; i++) {
        char c;
        scanf("%c", &c);
        for (int j=0; j<m; j++) {
            scanf("%c", &c);
            M[i][j] = c;
            
            if (isalpha(c)) {
                T[c].push_back(make_pair(i, j));
            } else if (c == '!') {
                ax = i;
                ay = j;
            } else if(c == '$') {
                bx = i;
                by = j;
            } else if(c == '*') {
                sx = i;
                sy = j;
                usedMap[i][j] = true;
            } else if(c == '#') {
                usedMap[i][j] = true;
            }
        }
    }
    
    used = usedMap;
    
    wave(ax, ay);
    
    int Ad[8];
    for (int i=0; i<8; i++) {
        if (isValid(sx+dx[i], sy+dy[i]) && (used[sx+dx[i]][sy+dy[i]] && !usedMap[sx+dx[i]][sy+dy[i]])) {
            Ad[i] = d[sx+dx[i]][sy+dy[i]];
        } else {
            Ad[i] = INF;
        }
    }
    used = usedMap;
    d.assign(n, vector<int>(m, 0));
    
    wave(bx, by);
    int Bd[8];
    for (int i=0; i<8; i++) {
        if (isValid(sx+dx[i], sy+dy[i]) && (used[sx+dx[i]][sy+dy[i]] && !usedMap[sx+dx[i]][sy+dy[i]])) {
            Bd[i] = d[sx+dx[i]][sy+dy[i]];
        } else {
            Bd[i] = INF;
        }
    }
    int mn = INF;
    for (int i=0; i<8; i++) {
        mn = min(mn, max(Bd[i], Ad[i]));
    }
    if (mn == INF) {
        printf("Impossible");
    } else {
        printf("%d", mn+1);
    }
    return 0;
}