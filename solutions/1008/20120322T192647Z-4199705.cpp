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
using namespace std;
//#define ONLINE_JUDGE
#define mp make_pair

int A[15][15];
int dx[] = { 1, 0, -1,  0 };
int dy[] = { 0, 1,  0, -1 };

queue< pair<int, int> > Q;

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //CODE
    int x, y;
    char str[20];
    gets(str);
    int scanResult = sscanf(str, "%d%d", &x, &y);
    if (scanResult==2) {
        string s; cin >> s;
        vector< pair<int, int> > Answer;
        Answer.push_back(mp(x,y));
        queue< pair<int, int> > Q;
        Q.push(mp(x,y));
        while (s!="." && !Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int i=0; s.size(); i++) {
                if (s[i] == 'R') {
                    Answer.push_back(mp(x+1,y));
                    Q.push(mp(x+1,y));
                } else if(s[i]=='T') {
                    Answer.push_back(mp(x,y+1));
                    Q.push(mp(x,y+1));
                } else if(s[i]=='B') {
                    Answer.push_back(mp(x,y-1));
                    Q.push(mp(x,y-1));
                } else if(s[i]=='L') {
                    Answer.push_back(mp(x-1,y));
                    Q.push(mp(x-1,y));
                } else {
                    cin >> s;
                    break;
                }
            }
        }
        sort(Answer.begin(), Answer.end());
        printf("%d\n", Answer.size());
        for (int i=0; i<Answer.size(); i++) {
            printf("%d %d\n", Answer[i].first, Answer[i].second);
        }
    } else {
        for (int i=0; i<15; i++)
            for (int j=0; j<15; j++)
                A[i][j]=0;
        int n = x;
        int as, bs; scanf("%d%d", &as, &bs);
        Q.push(make_pair(as, bs));
        for (int i=1; i<n; i++) {
            int a,b; scanf("%d%d", &a, &b);
            A[a][b] = 1;
        }
        
        A[as][bs] = 2;
        printf("%d %d\n", as, bs);
        while (!Q.empty()) {
            auto x = Q.front();
            Q.pop();
            if (A[x.first+dx[0]][x.second+dy[0]] == 1) {
                A[x.first+dx[0]][x.second+dy[0]] = 2;
                printf("R");
                Q.push(make_pair(x.first+dx[0], x.second+dy[0]));
            }
            if (A[x.first+dx[1]][x.second+dy[1]] == 1) {
                A[x.first+dx[1]][x.second+dy[1]] = 2;
                printf("T");
                Q.push(make_pair(x.first+dx[1], x.second+dy[1]));
            }
            if (A[x.first+dx[2]][x.second+dy[2]] == 1) {
                A[x.first+dx[2]][x.second+dy[2]] = 2;
                printf("L");
                Q.push(make_pair(x.first+dx[2], x.second+dy[2]));
            }
            if (A[x.first+dx[3]][x.second+dy[3]] == 1) {
                A[x.first+dx[3]][x.second+dy[3]] = 2;
                printf("B");
                Q.push(make_pair(x.first+dx[3], x.second+dy[3]));
            }
            printf(!Q.empty() ? ",\n" : ".");
        }
    }
    
    //END
#ifndef ONLINE_JUDGE
    fclose(stdout);
#endif    
    return 0;
}