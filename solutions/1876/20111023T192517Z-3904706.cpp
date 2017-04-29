#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a,b;
    
    scanf("%d%d", &a, &b);
    printf("%d", max(b*2+40, max(40+(a-40)*2 + 40, 1 + 39*2 + 40 + (a-40)*2)) );
    return 0;
}