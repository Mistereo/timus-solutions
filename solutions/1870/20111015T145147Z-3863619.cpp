#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    if (n%2 == 0 || n%3 == 0) {
        printf("No");
    } else {
        printf("Yes\n");
        int x = 2;
        for (int i=0; i<n; i++) {
            printf("%d ", x);
            x+=2;
            x%=n;
            if (x==0) {
                x = n;
            }
        }
    }
    return 0;
}
