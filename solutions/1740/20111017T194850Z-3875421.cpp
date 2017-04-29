#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double  const epsilon = 1e-6;

int main() {
    int l,k,h;
    scanf("%d%d%d", &l, &k, &h);
    
    if (l%k == 0) {
        printf("%d %d", l/k*h, l/k*h);
    } else {
        printf("%f %f", double(int(l/k)*h+epsilon), double(int(l/k)*h+h-epsilon));
    }
    return 0;
}