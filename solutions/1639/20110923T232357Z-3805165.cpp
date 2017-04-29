#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{    
    int n,k;
    scanf("%d%d", &n, &k);
    printf((n & 1 && k & 1) ? "[second]=:]" : "[:=[first]");
}
