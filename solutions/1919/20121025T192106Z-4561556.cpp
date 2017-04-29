#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 1000000000
#define EPS 1e-9

bool check(double H, double L, double w, double h) {

    if (h <= H && w <= L) {
        return true;
    }
    double x = sqrt(L*L-w*w);
    double xx = 2*w*w/(L-(L*L-w*w));
    //printf("%lf %lf %lf\n", x, xx, L*L-w*w);
    double y = w*w/x;
    double z = w*L/x;
    double a = z - H + floor(H/z)*z;
    double hh = y+L*L/x-a*L/w+(floor(H/z)-1)*(x+y);
    
    if (hh >= h - EPS) {
        return true;
    }
    return false;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int w, h;
    scanf("%d%d", &w, &h);
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int L, H;
        scanf("%d%d", &H, &L);
        if (w > h) {
            int tmp = w;
            w = h;
            h = tmp;
        }
        if ( check(H,L,w,h) || check(H, L, h, w)) {
            printf("Block the hole\n");
        } else {
            printf("Too small\n");
        }
    }
    
    return 0;
}