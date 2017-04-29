#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, nn;
    scanf("%d", &n);
    nn = n;
    int count = 0;
    while (nn!=1) { 
        nn=(nn+1)/2;
        count++;
    }
    printf("%d\n", count);
    while (n!=1) { 
        n=(n+1)/2;
        printf("%d ", n);
    }
    return 0;
}