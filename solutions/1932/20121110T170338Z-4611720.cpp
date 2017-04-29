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
#define INF 100000000
#define mp make_pair

typedef char str[5];

int64 n;
string *A;

template <int k>
bool cmp(string a, string b) {
    return a[k] < b[k];
}
template <int k1, int k2>
bool cmp(string a, string b) {
    if (a[k1] < b[k1]) return true;
    if (a[k1] > b[k1]) return false;
    return a[k2] < b[k2];
}
template <int k1, int k2, int k3>
bool cmp(string a, string b) {
    if (a[k1] < b[k1]) return true;
    if (a[k1] > b[k1]) return false;
    if (a[k2] < b[k2]) return true;
    if (a[k2] > b[k2]) return false;
    return a[k3] < b[k3];
}

template <int k>
int64 cnt() {
    int64 ans = 0;
    int64 cnt = 0;
    for (int i=0; i<n; i++) {
        if (i==0 || A[i][k]==A[i-1][k]) {
            cnt++;
        } else {
            ans += (cnt*(cnt-1))/2;
            cnt = 1;
        }
    }
    ans += (cnt*(cnt-1))/2;
    return ans;
}
template <int k1, int k2>
int64 cnt() {
    int64 ans = 0;
    int64 cnt = 0;
    for (int i=0; i<n; i++) {
        if (i==0 || (A[i][k1]==A[i-1][k1] && A[i][k2]==A[i-1][k2])) {
            cnt++;
        } else {
            ans += (cnt*(cnt-1))/2;
            cnt = 1;
        }
    }
    ans += (cnt*(cnt-1))/2;
    return ans;
}
template <int k1, int k2, int k3>
int64 cnt() {
    int64 ans = 0;
    int64 cnt = 0;
    for (int i=0; i<n; i++) {
        if (i==0 || (A[i][k1]==A[i-1][k1] && A[i][k2]==A[i-1][k2] && A[i][k3] == A[i-1][k3])) {
            cnt++;
        } else {
            ans += (cnt*(cnt-1))/2;
            cnt = 1;
        }
    }
    ans += (cnt*(cnt-1))/2;
    return ans;
}

int64 f(bool (*cmp)(string, string), int64 (*cnt)()) {
    sort(A, A+n, cmp);
    return cnt();
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%lld", &n);
    
    A = new string[n];
    for (int i=0; i<n; i++) cin >> A[i];
    
    int64 c1 = f(cmp<0>, cnt<0>);
    int64 c2 = f(cmp<1>, cnt<1>);
    int64 c3 = f(cmp<2>, cnt<2>);
    int64 c4 = f(cmp<3>, cnt<3>);
    
    int64 c12 = f(cmp<0,1>, cnt<0,1>);
    int64 c13 = f(cmp<0,2>, cnt<0,2>);
    int64 c14 = f(cmp<0,3>, cnt<0,3>);
    int64 c23 = f(cmp<1,2>, cnt<1,2>);
    int64 c24 = f(cmp<1,3>, cnt<1,3>);
    int64 c34 = f(cmp<2,3>, cnt<2,3>);
    
    int64 c123 = f(cmp<0,1,2>, cnt<0,1,2>);
    int64 c124 = f(cmp<0,1,3>, cnt<0,1,3>);
    int64 c134 = f(cmp<0,2,3>, cnt<0,2,3>);
    int64 c234 = f(cmp<1,2,3>, cnt<1,2,3>);
    
    int64 ans1 = (c123+c124+c134+c234);
    int64 ans2 = (c12+c13+c14+c23+c24+c34) - 3*(c123+c124+c134+c234);
    int64 ans3 = (c1+c2+c3+c4) - 2*(c12+c13+c14+c23+c24+c34) + 3*(c123+c124+c134+c234);
    int64 ans4 = (n*(n-1)/2)-ans1-ans2-ans3;
    printf("%lld %lld %lld %lld", ans1, ans2, ans3, ans4);
    
    return 0;
}
