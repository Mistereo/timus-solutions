#include <stdio.h>


int main (int argc, const char * argv[])
{
    //------------------------------------------
    int F[46] = {0};

    int n,k; scanf("%d%d", &n, &k);
    F[0] = 1;
    F[1] = 2;
    F[2] = 3;
    for (int i=3; i<46; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    
    if (k > F[n]) {
        printf("-1");
    } else {
        while (n!=0) {
            if (k <= F[n-1]) {
                printf("0");
                n--;
            } else {
                printf("1");
                k = k - F[n-1];
                n--;
            }
        }
    }
    
    //------------------------------------------
    return 0;
}