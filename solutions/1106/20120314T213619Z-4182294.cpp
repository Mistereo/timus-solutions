
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

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;

vector<char> used;
vector<char> colors;
vector< vector<int> > G;

void dfs(int v, int c) { 
    used[v] = true;
    colors[v] = c;
    for (int i=0; i<G[v].size(); i++) {
        if (!used[ G[v][i] ]) {
            dfs( G[v][i], (c+1)%2 );
        }
    }
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n;
    scanf("%d", &n);
    G.assign(n, vector<int>());
    used.assign(n, false);
    colors.assign(n, -1);
    for (int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        while (a!=0) {
            G[i].push_back(a-1);
            G[a-1].push_back(i);
            scanf("%d", &a);
        }
    }
    
    for (int i=0; i<n; i++) {
        if (!used[i]) {
            dfs(i, 0);
        }
    }
    
    vector<int> answer;
    

    for (int i=0; i<n; i++) {
        if (colors[i] == -1) {
            printf("0");
            exit(0);
        }
        if (colors[i] == 0) {
            answer.push_back(i+1);
        }
    }
    
    printf("%d\n", int(answer.size()));
    for (int i=0; i<answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}