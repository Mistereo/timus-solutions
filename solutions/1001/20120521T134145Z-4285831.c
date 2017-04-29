#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, const char * argv[]) {
    
    int size = 10000000;
    int id = 0;
    int i;
    double *A = (double*)malloc(sizeof(double)*size);
    
    double tmp;
    while (scanf("%lf", &tmp)!=EOF) {
        if (size==id) {
            A = (double*)realloc(A, sizeof(double)*size*2);
            size *= 2;
        }
        A[id++] = tmp;
    }
    for (i=id-1; i>=0; i--) {
        printf("%lf\n", sqrt(A[i]));
    }
    
    return 0;
}