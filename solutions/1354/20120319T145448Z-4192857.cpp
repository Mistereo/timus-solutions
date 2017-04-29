
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
    string s, sr;
    cin >> s;
    sr = s;
    if (s.size()==1) {
        printf("%s%s", s.c_str(), s.c_str());
        exit(0);
    }
    if (s.size()==2) {
        printf("%s%c", s.c_str(), s[0]);
        exit(0);
    }
    reverse(sr.begin(), sr.end());
    int n = int(s.size());
    for (int i=n/2; i<n; i++) {
        bool isOddPal = true;
        bool isEvenPal = true;
        if (i==n/2) {
            if (n&1) {
                isOddPal = false;
            } else {
                isEvenPal = false;
            }
        }
        int evenCnt = 0;
        int oddCnt = 0;

        for (int j=0; i+j<n && i-j >= 0; j++) {
            if (s[i-j]!=s[i+j]) {
                isOddPal = false;
            }
            if (s[i-j-1]!=s[i+j]) {
                isEvenPal = false;
            }
            evenCnt++;
            oddCnt++;
        }
        if (isEvenPal) {
                printf("%s", s.c_str());
                for (int i=evenCnt*2; i<n; i++) {
                    printf("%c", sr[i]);
                }
                exit(0);
        }
        if (isOddPal) {
                printf("%s", s.c_str());
                for (int i=oddCnt*2-1; i<n; i++) {
                    printf("%c", sr[i]);
                }
                exit(0);
        }
    }
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}