#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int k;
    scanf("%d", &k);
    
    long long a = 0,b = 2;
    for (int i=0; i<k; i++) {
        long long tmp = a;
        a = b;
        b = b + tmp;
    }
    printf("%lld", a);
    
    return 0;
}
