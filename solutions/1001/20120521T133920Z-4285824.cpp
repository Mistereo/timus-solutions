#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main (int argc, const char * argv[]) {
    
    int size = 1000000;
    int id = 0;
    double *A = (double*)malloc(sizeof(double)*size);
    
    double tmp;
    while (scanf("%lf", &tmp)!=EOF) {
        if (size==id) {
            A = (double*)realloc(A, sizeof(double)*size*2);
            size *= 2;
        }
        A[id++] = tmp;
    }
    int i;
    for (i=id-1; i>=0; i--) {
        printf("%lf\n", sqrt(A[i]));
    }
    
    return 0;
}