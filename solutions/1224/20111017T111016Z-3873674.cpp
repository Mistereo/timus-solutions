#include <iostream>

using namespace std;

int main() {
    long long n, m;
    scanf("%lld%lld", &n,&m);
    if (m>=n) {
        printf("%lld", (n-1)*2);
    } else {
        printf("%lld", (m-1)*2+1);
    }
    
    return 0;
}