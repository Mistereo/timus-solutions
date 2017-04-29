#define task H
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
    vector< pair<char, int> > P;
    vector<int> A;
    vector< pair<char, int> > S;
    void solve() {
        char T[10000];
        scanf("%d\n%s", &n, T);
        P.assign(2 * n, pair<char, int> ());
        A.assign(2 * n, -1);
        int cnt = 0;
        for (int i=0; T[i]!=0; i++) {
            P[i].first = T[i];
            if (tolower(P[i].first) == P[i].first) {
                P[i].second = cnt++;
            } else {
                P[i].second = i;
            }
        }
        for (int i=0; i< 2 * n; i++) {
            if (S.empty()) {
                S.push_back(P[i]);
            } else {
                auto c = S.back();
                if (c.first != P[i].first && tolower(c.first) == tolower(P[i].first)) {
                    if (c.first != tolower(c.first)) {
                        A[c.second] = P[i].second;
                    } else {
                        A[P[i].second] = c.second;
                    }
                    S.pop_back();
                } else {
                    S.push_back(P[i]);
                }
            }
        }
        if (!S.empty()) {
            printf("Impossible\n");
        } else {
            for (int i=0; i<2 * n; i++) {
                if (A[i]!=-1) {
                    printf("%d ", A[i] + 1);
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