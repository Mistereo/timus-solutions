#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main (int argc, const char * argv[])
{
    long long r;
    long long count = 0;
    scanf("%lld", &r);
    
    long long x=0,y=r-1;
    
    while (x<r) {
        while (x*x+y*y >= r*r) {
            y--;
        }
        count+=y + 1;
        x++;
    }
    
    printf("%lld", count*4);
    
    return 0;
}
