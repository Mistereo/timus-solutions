
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
    const long long P = 10000000000;
    int n;
    scanf("%d", &n);
    long long a = 1,b = 1,c = 1;
    for (int i=0; i<n; i++) {
        a*=2;
        a%=P;
        b*=3;
        b%=P;
        c*=4;
        c%=P;
    }
    long long d = (a+b+c+1)%P;
    int answer = 0;
    while (d!=0 && d%10==0) {
        answer++;
        d/=10;
    }
    printf("%d",answer);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}