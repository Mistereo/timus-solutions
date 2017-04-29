#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double  const epsilon = 1e-6;

int main() {
    int n1,n2,n3,c1,c2,t, k;
    scanf("%d%d%d%d%d%d%d", &n1, &c1, &n2, &t, &c2, &n3, &k);
    int time = 0;
    
    for (int i=0; i<k; i++) {
        int mm,ss;
        scanf("%d:%d", &mm, &ss);
        if (!(mm == 0 && ss < 7)) {
            if (ss!=0) {
                mm++;
            }
            time+=mm;
        }
    }
    printf("Basic:     %d\nCombined:  %d\nUnlimited: %d", time*c1+n1, 
           (time - t > 0 ? time - t : 0) * c2 + n2,
           n3);
    return 0;
}