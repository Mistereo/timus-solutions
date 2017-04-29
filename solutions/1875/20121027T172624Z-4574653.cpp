#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 2000000000
#define EPS 1e-6
#define int64 long long

const int n = 5;
int64 *X, *Y;

set<int> mark(int64 A, int64 B, int64 d, set<int> S) {
    set<int> R;
    for (set<int>::iterator it=S.begin(); it!=S.end(); it++) {
        int64 F = A*X[*it]*X[*it]+B*X[*it];
        if (d*Y[*it] == F) {
            
        } else {
            R.insert(*it);
        }
    }
    return R;
}

int build(set<int> S) {
    if(S.size() == 1)
        return 1;
    int answer = (int)S.size();
    for (set<int>::iterator i=S.begin(); i!=S.end(); i++) {
        for (set<int>::iterator j=S.begin(); j!=S.end(); j++) {
            if (i!=j) {
                int64 x2 = X[*i],y2 = Y[*i];
                int64 x3 = X[*j],y3 = Y[*j];
                int64 A,B;
                int64 d = x2*x2*x3-x3*x3*x2;
                A = y2*x3-y3*x2;
                B = y3*x2*x2-y2*x3*x3;
                if (A*d<0 && B!=0 && d!=0) {
                    answer = min(answer, 1 + build(mark(A, B, d, S)));
                }
            }
        }
    }
    return answer;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    set<int> *S = new set<int>();
    S->insert(0);
    S->insert(1);
    S->insert(2);
    S->insert(3);
    S->insert(4);
    int64 *XX = new int64[n];
    int64 *YY = new int64[n];
    X = XX;
    Y = YY;
    for (int i=0; i<n; i++) {
        scanf("%lld%lld", XX+i, YY+i);
    }
    printf("%d\n", build(*S));
    return 0;
}