#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double  const epsilon = 1e-6;

int main() {
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    
    pair<int, int> *ANS = new pair<int, int>[n];
    
    for (int i=0; i<n; i++) {
        int min = 1, max = n;
        for (int j=0; j<i; j++) {
            if (A[j]>A[i]) {
                min++;
            }
        }
        for (int j=i+1; j<n; j++) {
            if (A[j]<A[i]) {
                max--;
            }
        }
        ANS[A[i]-1].first = min;
        ANS[A[i]-1].second = max;
    }
    for (int i=0; i<n; i++) {
        printf("%d %d\n", ANS[i].first, ANS[i].second);
    }
    return 0;
}