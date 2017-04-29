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
    unsigned long long k = n;
    unsigned long long m = k*k;
    printf("%lld\n%lld", m, k);
    return 0;
}