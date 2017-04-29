#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
using namespace std;

const int N = 1000000;

double *X1;
double *X2;
double *R;

int n;

bool check(double x, double y) {
    for (int i=0; i<n; i++) {
        double a = x-X1[i];
        double b = y-X2[i];
        if (a*a+b*b <= R[i]*R[i])
            return true;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    srand(time(NULL));
    scanf("%d", &n);
    X1 = new double[n];
    X2 = new double[n];
    R  = new double[n];
    for (int i=0; i<n; i++)
        scanf("%lf%lf%lf", X1+i, X2+i, R+i);
    
    int IN = 0;
    int OUT = 0;
    
    for (int i=0; i<N; i++) {
        double x = (double)rand()/RAND_MAX;
        double y = (double)rand()/RAND_MAX;
        if (check(x, y))
            IN++;
        else
            OUT++;
    }
    printf("%.9lf", (double)IN/(OUT+IN)*100);
    
	return 0;
}