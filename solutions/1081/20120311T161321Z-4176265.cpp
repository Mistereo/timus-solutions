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

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short

using namespace std;
int F[46] = {0};
void printer(int n, int k) {
    if (n==0) return;
    if (k > F[n]) {
        printf("-1");
        exit(0);
    } else {
        if (k <= F[n-1]) {
            printf("0");
            printer(n-1, k);
        } else {
            printf("1");
            printer(n-1, k-F[n-1]);
        }
    }
}

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n,k; scanf("%d%d", &n, &k);
    F[0] = 1;
    F[1] = 2;
    F[2] = 3;
    for (int i=3; i<46; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    printer(n, k);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}