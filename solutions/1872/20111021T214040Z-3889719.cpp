#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int c = 0;
vector< vector<int> > g;
vector<int> mt;
vector<char> used;

bool kuhn(int v) {
    
    if(used[v]==1) return false;
    used[v] = true;
    for (int i=0; i<g[v].size(); i++) {
        int to = g[v][i];
        if (mt[to] == -1 || kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    
    scanf("%d", &n);
    int *S = new int[n];
    int *A = new int[n];
    int *B = new int[n];
    vector<int> tmp;
    g.assign(n, tmp);
    for (int i=0; i<n; i++) scanf("%d", &S[i]);
    for (int i=0; i<n; i++) scanf("%d%d", &A[i], &B[i]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ( A[j]<= S[i] && S[i] <= B[j]) {
                g[i].push_back(j);
            }
        }
    }
    mt.assign (n, -1);
    
    vector<char> used1 (n);
    
	for (int i=0; i<n; ++i)
		for (size_t j=0; j<g[i].size(); ++j)
			if (mt[g[i][j]] == -1) {
				mt[g[i][j]] = i;
				used1[i] = true;
                c++;
				break;
			}
	for (int v=0; v<n; ++v) {
        if (used1[v]) {
            continue;
        }
		used.assign (n, false);
		if(kuhn (v)) c++;
	}
    if (c!=n) {
        printf("Let's search for another office.\n");
        return 0;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (mt[j] == -1 || mt[i] == -1)
                continue;
            if( i!=j && A[j] <= S[mt[i]] && S[mt[i]] <= B[j] &&
               A[i] <= S[mt[j]] && S[mt[j]] <= B[i]
               ) {
                //cout << mt[i] << " " << mt[j];
                printf("Ask Shiftman for help.\n");
                return 0;
            }
        }
    }
    printf("Perfect!\n");
    for (int i=0; i<n; ++i)
		if (mt[i] != -1)
			printf ("%d ", mt[i]+1);
    return 0;
}