#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
#include <map>
using namespace std;
#define INF 1000000000
#define int64 long long
#define mp make_pair


#define N 1000500
#define P 1000000007

int n;
int64 res = 1;

int F[N+1];
int lp[N+1];
int ans[N+1];
bool isFactorised[N];
vector<int>pr;



void genP() {
    for (int i=2; i<=N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; j++) {
            lp[i*pr[j]] = pr[j];
        }
    }
}

void genF() {
    F[0] = 1;
    F[1] = 1;
    for (int i=2; i<N; i++) {
        F[i] = F[i-1] + F[i-2];
        F[i] %= P;
    }
}

void factorize(int x, int mult) {
    isFactorised[x] = true;
    while (x!=1) {
        ans[ lp[x] ]+=mult;
        ans[ lp[x] ]%=P;
        x /= lp[x];
    }
}

int main() {
#ifdef MISTMAC
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    for (int i=0; i<N; i++) {
        ans[i] = 0;
        lp[i] = 0;
    }
    genF();
    genP();
    for (int i=0; i<n; i++) {
        if (!isFactorised[n-i]) {
            factorize(n-i, F[i]);
        }
    }
    
    for (int i=0; i<N; i++) {
        if (ans[i]!=0) {
            res*=(ans[i]+1);
            res%=P;
        }
    }
    
    printf("%lld", res);
    
	return 0;
}