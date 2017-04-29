#define _USE_MATH_DEFINES
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define N 10000000


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    
    int *T = new int[n];
    for (int i=0; i<n; i++)
        scanf("%d", T+i);
    
    int k = n/2;
    
    int *A = new int[1<<k];
    int *B = new int[1<<(n-k)];
    for (int m=0; m<(1<<k); m++) {
        A[m] = 0;
        for (int i=0; i<k; i++) {
            if (m&(1<<i)) {
                A[m] += T[i];
            } else {
                A[m] -= T[i];
            }
        }
    }
    for (int m=0; m<(1<<(n-k)); m++) {
        B[m] = 0;
        for (int i=0; i<n-k; i++) {
            if (m&(1<<i)) {
                B[m] += T[k+i];
            } else {
                B[m] -= T[k+i];
            }
        }
    }
    int mn = 1000000000;
    for (int i=0; i<(1<<k); i++) {
        for (int j=0; j<(1<<(n-k)); j++) {
            mn = min(abs(A[i]+B[j]), mn);
        }
    }
    printf("%d", mn);
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}