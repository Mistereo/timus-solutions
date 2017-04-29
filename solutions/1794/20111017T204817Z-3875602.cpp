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
    memset(A, 0, n*sizeof(int));
    for (int i=0; i<n; i++) {
        int ai;
        scanf("%d", &ai);
        int x = (i-(ai-1))%n;
        //cout << x << " ";
        A[(x >= 0 ? x : x + n)]++;
    }
    //cout << endl;
    int mx = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        //cout << A[i] << " ";
        if (A[i] > mx) {
            mx = A[i];
            ans = i;
        }
    }
    //cout << endl;
    printf("%d", ans+1);
    return 0;
}