#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int A[7];
bool check(int pos) {
    A[pos] = !A[pos];
    if ((A[0] + A[1] + A[3])%2 == A[6] && 
        (A[0] + A[2] + A[3])%2 == A[5] && 
        (A[1] + A[2] + A[3])%2 == A[4]) {
        return true;
    } else {
        A[pos] = !A[pos];
        return false;
    }
}
int main() {
    for (int i=0; i<7; i++) scanf("%d", &A[i]);
    
    for (int i=0; i<7; i++)
        if(check(i)) break;
    
    for (int i=0; i<7; i++)
        printf("%d ", A[i]);
    return 0;
}