#define _USE_MATH_DEFINES
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
#include <cmath>
using namespace std;
#define int64 long long
#define mp make_pair

class pos {
public:
    pos(int64 p, int64 mx = 0, int64 mn = 0):p(p),mn(mn),mx(mx) {
        
    }
    int64 p;
    int64 mx;
    int64 mn;
    bool operator<(const pos &b) const {
        return p < b.p || (p==b.p && mn < b.mn) || (p == b.p && mn == b.mn && mx < b.mx);
    }
};

const int64  N = (1<<20)+100;

int64 A[N];
int64 B[N];
int64 idA = 0;
int64 idB = 0;
int64 K[40];

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int64 n,s,k;
    
    scanf("%lld%lld%lld", &n, &s, &k);
    
    for (int64 i=0; i<k; i++)
        scanf("%lld", K+i);
    
    int64 t1 = k/2;
    int64 t2 = k - t1;
    
    for (int64 m=0; m<(1<<t1); m++) {
        int64 H = s;
        bool good = true;
        for (int64 i=0; i<t1; i++) {
            if (m&(1<<i)) {
                H += K[i];
            } else {
                H -= K[i];
            }
            if (H < 0 || H > n) {
                good = false;
            }
        }
        if (good) {
            A[idA++] = H;
            B[idB++] = H;
        }
    }
    sort(A, A+idA);
    sort(B, B+idB, greater<int64>());
    int64 mn = 1000000001;
    int64 mx = -1;
    
    for (int64 m=0; m<(1<<t2); m++) {
        pos H(0);
        bool good = true;
        for (int64 i=0; i<t2; i++) {
            if (m&(1<<i)) {
                H.p += K[t1+i];
            } else {
                H.p -= K[t1+i];
            }
            H.mn = min(H.mn, H.p);
            H.mx = max(H.mx, H.p);
            if (H.mn < -1000001001 || H.mx > 1000001001) {
                good = false;
                break;
            }
        }
        if (good) {
            int64 it = (int64)(lower_bound(A, A+idA, -H.mn) - A);
            int64 it2 = (int64)(lower_bound(B, B+idB, n-H.mx, greater<int64>()) - B);
            
            if (it!=idA && 0 <= A[it]+H.p && A[it]+H.p <= n && 0<=A[it]+H.mn && A[it] + H.mx <= n) {
                mn = min(mn, H.p + A[it]);
                mx = max(mx, H.p + A[it]);
            }
            if (it2!=idB && 0 <= B[it2]+H.p && B[it2]+H.p <= n && 0<=B[it2]+H.mn && B[it2] + H.mx <= n) {
                mn = min(mn, H.p + B[it2]);
                mx = max(mx, H.p + B[it2]);
            }
        }
    }
    printf("%lld %lld\n", mn, mx);
    
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}