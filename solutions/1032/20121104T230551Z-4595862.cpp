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
#include <map>
using namespace std;
#define INF 1000000000
#define int64 long long
#define mp make_pair

#define N 1000500
#define P 1000000007

int A[10500];
int S[10500];

int main() {
#ifdef MISTMAC
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    int s = 0;
    S[0] = 0;
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
        s+=A[i];
        S[i+1]=s;
    }
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<i; j++) {
            if ((S[i]-S[j])%n==0) {
                printf("%d\n", i-j);
                for (int k=j; k<i; k++)
                    printf("%d ", A[k]);
                return 0;
            }
        }
    }
    
    printf("0\n");
    
	return 0;
}