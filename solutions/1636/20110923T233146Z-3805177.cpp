#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{    
    int t1,t2,tmp;
    scanf("%d%d", &t1, &t2);
    for (int i=0; i<10; i++) {
        scanf("%d", &tmp);
        t2 -= tmp*20;
    }
    printf((t1 > t2) ? "Dirty debug :(" : "No chance.");
}
