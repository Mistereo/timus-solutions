#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int const MSIZE = 140;
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int *A = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
        A[i]*=100;
        sum+=A[i];
    }
    int  p = sum/(n+1);
    
    int sum2 = 0;
    for (int i=0; i<n; i++) {
        if (A[i] - p > 0) {
            sum2 += (A[i] - p);
        }
    }
    for (int i=0; i<n; i++) {
        cout << ((A[i] - p > 0) ? ((A[i] - p)*100/sum2) : 0) << " ";
    }
    return 0;
}