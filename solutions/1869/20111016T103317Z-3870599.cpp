#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int const MSIZE = 140;
int main() {
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    memset(A, 0, n*sizeof(int));
    int **Data = new int*[n];
    for (int i=0; i<n; i++) {
        Data[i] = new int[n];
        for (int j=0; j<n; j++) {
            scanf("%d", &Data[i][j]);
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=i; k<j; k++) {
                A[k] += Data[i][j];
            }
        }
    }
    int mx = 0;
    for (int i=0; i<n; i++) {
        if (A[i] > mx) {
            mx = A[i];
        }
    }
    memset(A, 0, n*sizeof(int));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=j-1; k>=i; k--) {
                A[k] += Data[j][i];
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (A[i] > mx) {
            mx = A[i];
        }
    }
    printf("%d", (mx+35)/36);
    return 0;
}