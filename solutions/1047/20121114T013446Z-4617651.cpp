#pragma comment(linker, "/STACK:33554432")
#include <cstdio>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define int64 long long
#define INF 1000000
#define EPS 1e-9

int n;
double a0, an;
double *C;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d", &n);
    C = new double[n];
    scanf("%lf%lf", &a0, &an);
    for (int i=0; i<n; i++)
        scanf("%lf", C+i);
    double l = -2000;
    double r = 2000;
    double m;
    while (r-l > EPS) {
        m = (l+r)/2;
        double a = a0,b = m, ai;
        for (int i=2; i<n+2; i++) {
            //printf("%lf %lf %lf\n", a, b, C[i-2]);
            ai = 2*b - a + 2*C[i-2];
            a = b;
            b = ai;
            //printf("%lf\n", ai);
        }
        
        if (an > ai) {
            l = m;
        } else {
            r = m;
        }
    }
    printf("%.2lf", m);
    return 0;
}
