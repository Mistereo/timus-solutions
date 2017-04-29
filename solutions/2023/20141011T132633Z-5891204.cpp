#define task L
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

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
class L {
public:
    static void solve() {
        int n;
        char name[10];
        int pos = 0;
        int count = 0;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", name);
            int newPos;
            if (name[0] == 'A' || name[0] == 'P' || name[0] == 'O' || name[0] == 'R') {
                newPos = 0;
            } else if (name[0] == 'B' || name[0] == 'M' || name[0] == 'S') {
                newPos = 1;
            } else {
                newPos = 2;
            }
            count += abs(newPos - pos);
            pos = newPos;
        }
        printf("%d\n", count);
    }
};

int main(int argc, const char * argv[]) {
    task::solve();
    return 0;
}
