#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int xx, yy;
    
    int d = gcd(b%a, a, xx, yy);
    
    x = yy - (b/a) * xx;
    y = xx;
    return d;
}

void factorize(int n, int &p, int &q) {
    int i;
    for (i=2; i*i<n+1; i++) {
        if (n%i == 0) {
            n/=i;
            p = i;
            break;
        }
    }
    for (; i*i<n+1; i++) {
        if (n%i == 0) {
            n/=i;
            q = i;
            break;
        }
    }
    if (n > 1) {
        q = n;
    }
}

int main (int argc, const char * argv[])
{
    int k;
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        int n;
        scanf("%d", &n);
        int p,q;
        factorize(n,p,q);
        int x, y;
        gcd(p, q, x, y);
        
        int ans1 = p*x;
        int ans2 = q*y;
        
        if (ans1 < 0) ans1+=n;
        if (ans2 < 0) ans2+=n;
        if (ans1 > ans2) swap(ans1, ans2);
        
        printf("0 1 %d %d\n", ans1, ans2);
    }
    return 0;
}