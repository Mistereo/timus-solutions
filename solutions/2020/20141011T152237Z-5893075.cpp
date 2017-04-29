#define task I
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
class H {
public:
    static void solve() {
        
    }
};
class I {
public:
    char S[200000];
    char N[200000];
    void solve() {
        scanf("%s%s", S, N);
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (S[i]!=0 && N[j]!=0) {
            cnt++;
            if ((S[i] == 'F' || S[i] == 'R') && (N[j] == 'R' || N[j]=='F')) {
                i++;
                j++;
            } else if (S[i] == 'L' && N[j] == 'L') {
                i++;
                j++;
            } else if (S[i]=='F' || S[i]=='R') {
                i++;
            } else {
                j++;
            }
        }
        while(S[i++]!=0) cnt++;
        while(N[j++]!=0) cnt++;
        printf("%d\n", cnt);
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
