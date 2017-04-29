#define task J
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
using namespace std;
#define uint64 unsigned long long

class B {
public:
    static void solve() {
        
    }
};
class C {
public:
    static void solve() {
        
    }
};
class E {
public:
    static void solve() {
        
    }
};
class F {
public:
    static void solve() {
        
    }
};
class H {
public:
    int n;
    char P[10000];
    int C[5010][5010];
    bool check(int a, int b) {
        if (b - a <= 0) return true;
        if (!((b - a) & 1)) return false;
        if (C[a][b] != -1) return C[a][b];
        
        for (int i=0; a + i<=b; i++) {
            if (P[a] != P[a+i]) {
                if (P[a] == tolower(P[a+i]) || tolower(P[a]) == P[a+i]) {
                    int m = a + i;
                    int c1 = C[a + 1][m - 1] = check(a + 1, m - 1);
                    int c2 = C[m+1][b] = check(m + 1, b);
                    if (c1 && c2) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    void solve() {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%c", &P[i]);
        }
        int a = 0;
        int b = n-1;
        while (a != b) {
            
        }
    }
};
class J {
public:
    int n;
    int A[10];
    int B[10];
    int Ai[10];
    int Bi[10];
    vector<int> AP[10];
    vector<int> BP[10];
    void solve() {
        for (int i=0; i<10; i++) {
            A[i] = B[i] = Ai[i] = Bi[i] = 0;
        }
        scanf("%d", &n);
        int amin = 10;
        int amax = 0;
        int afull = 0;
        
        int bmin = 10;
        int bmax = 0;
        int bfull = 0;
        for (int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            A[a]++;
            AP[a].push_back(i);
            afull += a;
            amin = min(amin, a);
            amax = max(amax, a);
        }
        for (int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            B[a]++;
            BP[a].push_back(i);
            bfull += a;
            bmin = min(bmin, a);
            bmax = max(bmax, a);
        }
        if (afull < bfull) {
            for (int i=0; i<n; i++) {
                printf("%d %d\n", AP[amax][Ai[amax]++] + 1, BP[bmin][Bi[bmin]++] + 1);
                A[amax]--;
                B[bmin]--;
                if (A[amax]==0) {
                    while (!A[amax]) amax--;
                }
                if (B[bmin]==0) {
                    while (!B[bmin]) bmin++;
                }
            }
        } else {
            for (int i=0; i<n; i++) {
                printf("%d %d\n", AP[amin][Ai[amin]++] + 1, BP[bmax][Bi[bmax]++] + 1);
                A[amin]--;
                B[bmax]--;
                if (A[amin]==0) {
                    while (!A[amin]) amin++;
                }
                if (B[bmax]==0) {
                    while (!B[bmax]) bmax--;
                }
            }
        }
    }
};
class K {
public:
    static void solve() {
        
    }
};

int main(int argc, const char * argv[]) {
    (new task)->solve();
    return 0;
}