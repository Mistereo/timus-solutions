#define _USE_MATH_DEFINES
#include <map>
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
#define mp make_pair
#define pb push_back
#define int64 long long

#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)

#define INF 2*1000*1000*1000+1000

#define ld long double

int64 calc(int64 i, int64 a, int64 b, int64 k) {
    int64 cur = i+1;
    while (cur != k) {
        if (b < -2*1000*1000*1000LL || b > 2*1000*1000*1000LL) {
            break;
        }
        cur++;
        swap(a, b);
        b += a;
    }
    return b;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int64 i, Fi, j, Fj, n;
    scanf("%lld%lld%lld%lld%lld", &i, &Fi, &j, &Fj, &n);
    
    int64 l = -2*1000*1000*1000-100;
    int64 r =  2*1000*1000*1000+100;
    
    if (j < i) {
        swap(i, j);
        swap(Fi, Fj);
    }
    
    while (l < r) {
        int64 m = l + (r - l)/2;
        if (Fj <= calc(i, Fi, m, j)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    int64 a = Fi;
    int64 b = r;
    
    if (n >= i) {
        while (n!=i) {
            n--;
            swap(a, b);
            b += a;
        }
    } else {
        while (n!=i) {
            n++;
            swap(a, b);
            a -= b;
        }
    }
    
    printf("%lld", a);
    
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}