#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
int a[200][200];

int main() {
    int n;
    scanf("%d", &n);
    n++;
    for(int i = 0; i < n; i++){
        a[0][i] = 0;
        a[i][0] = 0;
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            a[i][j] += a[i][j - 1];
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] += a[i - 1][j];
        }
    }
    int mx = (int)-1e9;
    //int t[4];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            for(int k = 0; k < i; k++){
                for(int p = 0; p < j; p++){
                    mx = max(mx, a[i][j] + a[k][p] - a[k][j] - a[i][p]);
                    /*
                    t[0] = i;
                    t[1] = j;
                    t[2] = k;
                    t[3] = p;
                    //*/
                }
            }
        }
    }
    /*
    for(int i = 0; i < n; i++){
        for(int j = 0;
    ][j]);
        }
        printf("\n");
    }
     //*/
    //printf("%d\n%d %d %d %d", mx, t[0], t[1],  t[2], t[3]);
    printf("%d", mx);
    return 0;
}