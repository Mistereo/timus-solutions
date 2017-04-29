#include <iostream>

using namespace std;

int main (int argc, const char * argv[])
{
    int n,m;
    scanf("%d%d", &n,&m);
    
    for (int i=0; i<n; i++) printf("%d ", i+1);
    printf("\n");
    for (int i=0; i<m; i++) printf("%d ", (i + 1) * 100);
    
    return 0;
}