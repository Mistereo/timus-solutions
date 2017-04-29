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

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;

vector<char> used;
vector< vector<int> > G;

int counter = 0;

void dfs(int v) {
    counter++;
    used[v] = 1;
    for (int i=0; i<G[v].size(); i++) {
        if (!used[ G[v][i] ]) {
            dfs( G[v][i] );
        }
    }
}

int gcd (int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int lcm (int a, int b) {
	return a / gcd (a, b) * b;
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
    used.assign(n, 0);
    
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        G[i].push_back(x-1);
    }
    vector<int> cycles;
    for (int i=0; i<n; i++) {
        if (!used[i]) {
            counter = 0;
            dfs(i);
            cycles.push_back(counter);
        }
    }
    int answer = 1;
    for (int i=0; i<cycles.size(); i++) {
        answer = lcm(answer, cycles[i]);
    }
    printf("%d", answer);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}