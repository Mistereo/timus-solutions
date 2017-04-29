#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    printf("%d\n", 2*n);
    for (int i=0; i<n; i++) {
        printf("%d ", i+1);
    }
    for (int i=0; i<n; i++) {
        printf("%d ", n-i);
    }
    return 0;
}