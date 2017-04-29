#include <stdio.h>

int main (int argc, const char * argv[])
{
    int n, s;
    scanf("%d%d", &n, &s);
    s--;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        
        printf("%d ", s/x);
        s %= x;
    }
    
    return 0;
}