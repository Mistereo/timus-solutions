#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map< string, int> names;
vector< pair< vector<int>, int> > G;

int main (int argc, const char * argv[])
{
    int n, k;
    scanf("%d%d" , &n, &k);
    
    int rowsCount = (n + k-1) / k, *A;
    A = new int[n];
    
    for (int i=0; i<n; i++) scanf("%d", &A[i]);
    
    for (int i=0; i<rowsCount; i++) {
        for (int j=0; j<k && i + j*rowsCount < n; j++) {
            printf("%4d", A[i + j*rowsCount]);
        }
        printf("\n");
    }
    
    return 0;
}
