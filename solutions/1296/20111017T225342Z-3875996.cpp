#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double const epsilon = 1e-6;

int main() {
    int n;
    scanf("%d",&n);
    int *A = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    int mx = 0;
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum+=A[i];
        mx = max(sum, mx);
        if(sum < 0) {
            sum=0;
        }
    }
    printf("%d", mx);
    return 0;
}