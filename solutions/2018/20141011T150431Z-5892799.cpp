#define task G
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
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
class D {
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
class G {
public:
    int n, a, b;
    const uint64 M = 1e9 + 7;
    vector< uint64 > CA;
    vector< uint64 > CB;
    uint64 ca(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        //if (a == 1) return 1 + cb(n-1);
        
        if (CA[n]!=-1) return CA[n];
        uint64 result = (a < n) ? 0 : 1;
        for (int i=1; i<=a; i++) {
            if (n-i > 0) {
                result += cb(n-i);
                result %= M;
            }
        }
        CA[n] = result;
        return result;
    }
    uint64 cb(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        //if (b == 1) return 1 + ca(n-1);

        if (CB[n]!=-1) return CB[n];
        uint64 result = (b < n) ? 0 : 1;
        for (int i=1; i<=b; i++) {
            if (n-i > 0) {
                result += ca(n-i);
                result %= M;
            }
        }
        CB[n] = result;
        return result;
    }
    void solve() {
        CA.assign(60000, -1);
        CB.assign(60000, -1);
        scanf("%d%d%d", &n, &a, &b);
        uint64 x = ca(n);
        
        uint64 y = cb(n);
//        printf("%llu, %llu\n", x, y);
        printf("%llu\n", (x + y)%M);
    }
};
class H {
public:
    static void solve() {
        
    }
};
class I {
public:
    static void solve() {
        
    }
};
class J {
public:
    static void solve() {
        
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
