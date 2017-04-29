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
#define WHITE 1
#define BLACK 2
#define EMPTY 0

int dx[4] = { -1, -1, 1,  1 };
int dy[4] = { -1,  1, 1, -1 };

int dr[4] = { 2, 3, 0, 1 };

const int n = 8;

int A[n][n];

bool isValid(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}

bool check(int x, int y, int color) {
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        int rnx = x+dx[ dr[i] ];
        int rny = y+dy[ dr[i] ];
        if (isValid(nx, ny) && isValid(rnx, rny)) {
            if (A[nx][ny]!=EMPTY && A[nx][ny]!=color && A[rnx][rny]==EMPTY)
                return true;
        }
    }
    return false;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char move[5];
    int color = 0;
    int answer = 0;
    while (scanf("%s", move)!=EOF) {
        char x = move[0] - 'a';
        char y = move[1] - '1';
        A[x][y] = color%2+1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (A[i][j]!=EMPTY && check(i, j, A[i][j])) {
                    printf("%d\n", answer+1);
                    exit(0);
                }
            }
        }
        answer++;
        color++;
    }
    printf("Draw\n");
    return 0;
}