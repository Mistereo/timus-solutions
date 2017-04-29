#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{    
    int n, k, t1, t2;
    scanf("%d%d%d%d", &n, &k, &t1, &t2);
    if (t2>t1) printf("%d",(t2-t1-1)*(2*k+n)+2*k); 
    else printf("%d",(t1-t2)*(k+k+n)+n); 
    //|[  ||  ||  ||  ]||  ||  ||  |
}
