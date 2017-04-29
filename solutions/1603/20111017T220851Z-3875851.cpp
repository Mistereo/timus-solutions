#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
char A[4][4];
bool used[4][4];
int n;
string str;
bool x = false;
void wave(int i, int j, int pos) {
    if (x) return;
    if (used[i][j]) return;
    if (i<0 || i>=4 || j<0 || j>=4) return;
    if (A[i][j]!=str[pos]) 
        return;
    if (pos == str.size()-1) {
        x = true;
        return;
    }
    
    used[i][j] = true;
    wave(i, j+1, pos+1); 
    wave(i+1, j, pos+1);
    wave(i, j-1, pos+1);
    wave(i-1, j, pos+1);
    used[i][j] = false;
}

int main() {
    memset(used, 0, 16);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            //A[i][j] = 0;
            while (97 > A[i][j] || A[i][j]>122) {
                scanf("%c", &A[i][j]);
            }
        }
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        cin >> str;
        x = false;
        for (int j=0; j<4 && !x; j++) {
            for (int k=0; k<4 && !x; k++) {
                wave(j, k, 0);
            }
        }
        if (x) {
            printf("%s: YES\n", str.c_str());
        } else {
            printf("%s: NO\n", str.c_str());
        }
    }
    return 0;
}