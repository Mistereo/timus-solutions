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

#define N 2000
#define INF (1000*1000000)

struct Poly {
    vector<int> a;
    void scan() {
        a.assign(5, 1);
        for(int i = 3; i >= 0; i--) {
            scanf("%d", &a[i]);
        }
    }
    int f(int x) {
        int res = 0;
        for(int i = (int)a.size()-1; i >= 0; i--) {
            res *= x;
            res += a[i];
        }
        return res;
    }
    vector<int> findRoots() {
        vector<int> res;
        if(f(0) % 2 == 1 && f(1) % 2 == 1)
            return res;
        if(a[0] == 0) {
            Poly tmp = *this;
            tmp.a.erase(tmp.a.begin());
            auto t = tmp.findRoots();
            t.push_back(0);
            return t;
        }
        for(int d = 1; d <= abs(a[0]); d++) {
            if(abs(a[0])%d == 0) {
                if(f(d) == 0) {
                    res.push_back(d);
                    Poly next = divide(d);
                    auto nextroots = next.findRoots();
                    for(int i = 0; i < nextroots.size(); i++) {
                        res.push_back(nextroots[i]);
                    }
                    break;
                } else if(f(-d) == 0) {
                    res.push_back(-d);
                    Poly next = divide(-d);
                    auto nextroots = next.findRoots();
                    for(int i = 0; i < nextroots.size(); i++) {
                        res.push_back(nextroots[i]);
                    }
                    break;
                }
            }
        }
        return res;
    }
    Poly divide(int t) {
        if(a.size() == 5)
            return third(t);
        else if(a.size() == 4)
            return second(t);
        else if(a.size() == 3)
            return first(t);
        else {
            Poly res;
            res.a.push_back(1);
            return res;
        }
    }
    pair<Poly, Poly> checkTwo(int q) {
        int n = a[0]/q;
        if(q != n) {
            if((a[1]-a[3]*n)%(q-n) != 0)
                return mp(Poly(), Poly());
            int m = (a[1]-a[3]*n)/(q-n);
            int p = a[3] - m;
            if(n + p*m + q == a[2]) {
                Poly fst;
                fst.a.push_back(q);
                fst.a.push_back(p);
                fst.a.push_back(1);
                Poly snd;
                snd.a.push_back(n);
                snd.a.push_back(m);
                snd.a.push_back(1);
                return mp(fst, snd);
            }
            return mp(Poly(), Poly());
        } else {
            if(a[1]%q != 0 || a[1]/q != a[3])
                return mp(Poly(), Poly());
            int D2 = a[3]*a[3]-4*(a[2]-2*q);
            if(D2 < 0)
                return mp(Poly(), Poly());
            int D = int(sqrt((double)D2)+0.5);
            for(int i = -1; i <= 1; i++) {
                if(D+i >= 0 && (D+i)*(D+i) == D2) {
                    D = D+i;
                    break;
                }
            }
            if(D*D != D2 || (a[3]+D)%2 != 0)
                return mp(Poly(), Poly());
            int m1 = (a[3]+D)/2;
            int m2 = (a[3]-D)/2;
            
            if (m1!=m2) {
                Poly fst;
                fst.a.push_back(q);
                fst.a.push_back(m2);
                fst.a.push_back(1);
                Poly snd;
                snd.a.push_back(n);
                snd.a.push_back(m1);
                snd.a.push_back(1);
                return mp(fst, snd);
            }
            
            if(a[2] != 2*q)
                return mp(Poly(), Poly());
            
            int p = 0, m = 0;
            Poly fst;
            fst.a.push_back(q);
            fst.a.push_back(p);
            fst.a.push_back(1);
            Poly snd;
            snd.a.push_back(n);
            snd.a.push_back(m);
            snd.a.push_back(1);
            return mp(fst, snd);
        }
    }
    pair<Poly, Poly> twotwo() {
        for(int q = 1; q <= abs(a[0]); q++) {
            if(abs(a[0])%q == 0) {
                auto t1 = checkTwo(q);
                if(t1.first.a.size() != 0)
                    return t1;
                t1 = checkTwo(-q);
                if(t1.first.a.size() != 0)
                    return t1;
            }
        }
        return mp(Poly(), Poly());
    }
    Poly third(int t) {
        Poly res;
        int p = a[3]+t;
        int q = a[2]+t*p;
        int n = a[1]+t*q;
        res.a.push_back(n);
        res.a.push_back(q);
        res.a.push_back(p);
        res.a.push_back(1);
        return res;
    }
    Poly second(int t) {
        Poly res;
        int aa = a[2]+t;
        int bb = a[1]+t*aa;
        res.a.push_back(bb);
        res.a.push_back(aa);
        res.a.push_back(1);
        return res;
    }
    Poly first(int t) {
        Poly res;
        int aa = a[1]+t;
        res.a.push_back(aa);
        res.a.push_back(1);
        return res;
    }
    void print() {
        printf("(");
        bool printed = false;
        for(int i = (int)a.size()-1; i >= 0; i--) {
            if(printed && a[i] > 0)
                printf("+");
            if(i == 0) {
                if(a[i] != 0)
                    printf("%d", a[i]);
                printed = true;
            } else {
                if(a[i] != 0) {
                    if(a[i] != 1)
                        printf("%d", a[i]);
                    printf("x");
                    if(i != 1)
                        printf("%d", i);
                    printed = true;
                }
            }
            
        }
        printf(")");
    }
};

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    Poly f;
    f.scan();
    auto roots = f.findRoots();
    if(roots.size() == 1) {
        if(roots[0] > 0)
            printf("(x%d)", -roots[0]);
        else if(roots[0] < 0)
            printf("(x+%d)", -roots[0]);
        else
            printf("(x)");
        Poly g = f.third(roots[0]);
        g.print();
    } else if(roots.size() == 4) {
        for(int i = 0; i < roots.size(); i++) {
            if(roots[i] > 0)
                printf("(x%d)", -roots[i]);
            else if(roots[i] < 0)
                printf("(x+%d)", -roots[i]);
            else
                printf("(x)");

        }
    } else if(roots.size() == 2){
        for(int i = 0; i < roots.size(); i++) {
            if(roots[i] > 0)
                printf("(x%d)", -roots[i]);
            else if(roots[i] < 0)
                printf("(x+%d)", -roots[i]);
            else
                printf("(x)");
        }
        Poly tmp = f.divide(roots[0]);
        tmp = tmp.divide(roots[1]);
        tmp.print();
    } else {
        auto p = f.twotwo();
        if(p.first.a.size() != 0) {
            p.first.print();
            p.second.print();
        } else {
            printf("Irreducible");
        }
    }
    
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}