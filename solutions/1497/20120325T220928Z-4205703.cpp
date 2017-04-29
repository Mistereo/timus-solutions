#include <iostream>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    char **A = new char*[n];
    for (int i=0; i<n; i++) {
        A[i] = new char[n];
    }
    char c;
    scanf("%c", &c);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            scanf("%c", &A[i][j]);
        scanf("%c", &c);
    }
    bool horizontal = true;
    
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=1; j<n; j++) {
            if (A[i][j]!=A[i][j-1]) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            horizontal = false;
            break;
        }
    }
    if (horizontal) {
        printf("Yes");
        return 0;
    }
    bool vertical = true;
    
    for (int i=0; i<n; i++) {
        int cnt = 0;
        for (int j=1; j<n; j++) {
            if (A[j][i]!=A[j-1][i]) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            vertical = false;
            break;
        }
    }
    if (vertical) {
        printf("Yes");
        return 0;
    }
    printf("No");
    return 0;
}