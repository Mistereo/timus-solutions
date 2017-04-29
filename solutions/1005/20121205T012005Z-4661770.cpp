#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define int64 long long
#define uint64 unsigned int64
#define uint unsigned int
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)

const int INF = 1000*1000*1000;
const double EPS = 1e-10;


int main (int argc, const char * argv[])
{
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //--------------------------------------
    
    int n;
    scanf("%d", &n);
    int A[100500];
    int H[100500];
    rep(i, n) scanf("%d", A+i);
    
    int n1 = n/2;
    int n2 = n - n1;
    rep(m, (1<<n1)) {
        H[m] = 0;
        rep(i, n1) {
            if (m & (1 << i)) H[m] += A[i];
            else H[m] -= A[i];
        }
    }
    int ans = 1000000000;
    rep(m, (1<<n2)) {
        int S = 0;
        rep(i, n2) {
            if (m&(1<<i)) S+= A[n1+i];
            else S -= A[n1+i];
        }
        rep(i, (1<<n1)) {
            if (abs(S+H[i]) < ans) {
                ans = abs(S+H[i]);
            }
        }
    }
    printf("%d\n", ans);
    //--------------------------------------
#ifdef MISTMAC
	fclose(stdout);
	fclose(stdin);
#endif
    return 0;
}