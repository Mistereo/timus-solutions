#define task D
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
#define uint64 unsigned long long

#define money first
#define adv second

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
    struct apartment {
        int rooms;
        int cost;
        int adv;
    };
public:
    int money, advAloneOneRoom, advAloneTwoRooms;
    int n, m;
    vector< pair<int, int> > fr;
    vector< apartment > aprt;
    void solve() {
        scanf("%d%d%d%d", &money, &advAloneOneRoom, &advAloneTwoRooms, &n);
        fr.assign(n, pair<int, int>());
        for (int i=0; i<n; i++) {
            scanf("%d%d", &fr[i].money, &fr[i].adv);
        }
        scanf("%d", &m);
        aprt.assign(m, apartment());
        for (int i=0; i<m; i++) {
            scanf("%d%d%d", &aprt[i].rooms, &aprt[i].cost, &aprt[i].adv);
        }
        int bestFr = -1;
        int maxAdv = -1;
        int bestAprt = -1;
        for (int i=0; i<m; i++) {
            if (money >= aprt[i].cost) {
                int curAdv = (aprt[i].rooms == 1) ? advAloneOneRoom : advAloneTwoRooms;
                curAdv += aprt[i].adv;
                if (maxAdv < curAdv) {
                    maxAdv = curAdv;
                    bestAprt = i;
                    bestFr = -1;
                }
            }
            if (aprt[i].rooms == 2) {
                for (int k=0; k<n; k++) {
                    int cost = aprt[i].cost;
                    if (money * 2 >= cost && fr[k].money * 2 >= cost) {
                        int curAdv = fr[k].adv + aprt[i].adv;
                        if (maxAdv < curAdv) {
                            maxAdv = curAdv;
                            bestAprt = i;
                            bestFr = k;
                        }
                    }
                }
            }
        }
        
        if (bestAprt == -1) {
            printf("Forget about apartments. Live in the dormitory.\n");
            return;
        }
        if (bestFr == -1) {
            printf("You should rent the apartment #%d alone.\n", bestAprt+1);
        } else {
            printf("You should rent the apartment #%d with the friend #%d.\n", bestAprt+1, bestFr+1);
        }
        
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
