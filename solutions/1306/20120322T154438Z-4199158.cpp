
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
#include <time.h>

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

    priority_queue<unsigned int> S;
    int n; scanf("%d", &n);
    for (int i=0; i<n/2+1; i++) {
        int a; scanf("%u", &a);
        S.push(a);
    }
    for (int i=n/2+1; i<n; i++) {
        int a; scanf("%u", &a);
        S.push(a);
        S.pop();
    }
    if(n & 1) {
		printf("%u",S.top());
	} else {
        unsigned x = S.top();
        S.pop();
        x+=S.top();
		if (x&1)
			printf("%u.5",x/2);
		else
			printf("%u",x/2);
	}
    
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}