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

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int A[10][10];
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    int numbers[] = { A[0][0], A[0][3], A[3][3], A[3][0] };
    
    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<4; k++)
                if (A[i][j]==numbers[k]) {
                    A[i][j] = k + 1;
                    break;
                }
    
    int answer = 1000000000;
    
    for (int k=0; k<4; k++) {
        for (int p=0; p<4; p++) {
            int tmp = 0;
            for (int i=0; i<2; i++) {
                for (int j=0; j<2; j++) {
                    tmp+=abs((A[i][j]+k)%4 - p);
                }
            }
            answer = min(tmp, answer);
        }
    }

    printf("%d", answer);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}