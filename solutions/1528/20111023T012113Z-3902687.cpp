#include <iostream>
#include <set>
using namespace std;
int main() {
    int n,p;
    scanf("%d%d", &n, &p);
    while (n!=0 && n!=0) {
        long long res = 1;
        for (int i=2; i<=n; i++) res = (res*i)%p;
        printf("%lld\n", res);
        scanf("%d%d", &n, &p);
    }
    return 0;
}