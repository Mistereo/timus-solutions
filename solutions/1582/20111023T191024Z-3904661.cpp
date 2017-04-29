#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    long double k1,k2,k3;
    scanf("%Lf%Lf%Lf", &k1, &k2, &k3);
    printf("%.0Lf", 1000*k2*k3/(k1*(k2+k3)+k2*k3)*k1);
    return 0;
}