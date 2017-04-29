#include <iostream>
#include <cmath>
using namespace std;

struct point {
    double x,y,z;
};

int main() {
    int A,B,C;
    scanf("%d%d%d", &A, &B, &C);
    
    double x1, y1;
    double x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

    point a;
    
    // A - x B - y C - z
    // x
    if (x1 <= C) a.x = 0;
    else if (x1 <= C+A) a.x = x1 - C;
    else a.x = A;
    
    // y
    
    if (y1 <= B) a.y = B-y1;
    else if (y1 <= B+C) a.y = 0;
    else if (y1 <= 2*B+C) a.y = y1 - B - C;
    else a.y = B;
    
    // z
    if (y1 <= B) a.z = 0;
    else if (y1 <= B+C && x1 <= C+A && x1 >= C) a.z = y1-B; //
    else if (x1 <= C && y1 <= 2*B+C) a.z = x1;
    else if (x1 >= C+A && y1 <= 2*B+C) a.z = A+C+C - x1;
    else if (y1 >= B+C+B) a.z = 2*(B+C) - y1;
    else a.z = C;
    
    point b;
    // x
    if (x2 <= C) b.x = 0;
    else if (x2 <= C+A) b.x = x2 - C;
    else b.x = A;
    
    // y
    
    if (y2 <= B) b.y = B-y2;
    else if (y2 <= B+C) b.y = 0;
    else if (y2 <= 2*B+C) b.y = y2 - B - C;
    else b.y = B;
    
    // z
    if (y2 <= B) b.z = 0;
    else if (y2 <= B+C && x2 <= C+A && x2 >= C) b.z = y2 - B;
    else if (x2 <= C && y2 <= 2*B+C) b.z = x2;
    else if (x2 >= C+A && y2 <= 2*B+C) b.z = A+C+C - x2;
    else if (y2 >= B+C+B) b.z = 2*(B+C) - y2;
    else b.z = C;
    
    long double difx = (a.x-b.x);
    long double dify = (a.y-b.y);
    long double difz = (a.z-b.z);
    //printf("%lf %lf %lf\n%lf %lf %lf", a.x, a.y, a.z, b.x, b.y, b.z);
    printf("%.7Lf", sqrt(difx*difx+dify*dify+difz*difz));
    return 0;
}