
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
    
    int a;
    scanf("%d", &a);
    for (int i=1; i<n; i++) {
        int b; scanf("%d", &b);
        while (a!=b) {
            if (a < b) {
                int d = b%a;
                if (d==0) {
                    b = a;
                } else {
                    b = d;
                }
            } else {
                int d = a%b;
                if (d==0) {
                    a = b;
                } else {
                    a = d;
                }
            }
        }
    }
    printf("%d", a);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}