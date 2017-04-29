
#ifndef ONLINE_JUDGE
#include <ctime>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <sstream>
#include <cmath>

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;

long long abc(long long a) {
    return a >= 0 ? a : -a;
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n;
    scanf("%d", &n);
    
    double radius = 0;
    
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        double tmp = sqrt((double)(a*a+b*b));
        if (tmp > radius) {
            radius = tmp;
        }
    }
    
    printf("%d %d %.10lf", 0, 0, radius);
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}