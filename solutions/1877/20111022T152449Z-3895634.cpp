#include <iostream>

using namespace std;

int main() {
    int a,b;
    
    scanf("%d%d", &a, &b);
    if (a%2==0 || b%2==1) {
        printf("yes");
    } else {
        printf("no");
    }
    return 0;
}