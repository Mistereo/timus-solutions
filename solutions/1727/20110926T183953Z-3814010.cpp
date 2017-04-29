#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string str;

int main (int argc, const char * argv[])
{
    int n, count=0;

    scanf("%d", &n);
    int nn = n;
    for (int i1=9; i1>=0 && n; i1--) {
        for (int i2=9; i2>=0 && n; i2--) {
            for (int i3=9; i3>=0 && n; i3--) {
                for (int i4=9; i4>=0 && n; i4--) {
                    int sum = i1+i2+i3+i4;
                    if (n-sum >=0) {
                        n-=sum;
                        count++;
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    for (int i1=9; i1>=0 && nn; i1--) {
        for (int i2=9; i2>=0 && nn; i2--) {
            for (int i3=9; i3>=0 && nn; i3--) {
                for (int i4=9; i4>=0 && nn; i4--) {
                    int sum = i1+i2+i3+i4;
                    if (nn-sum >=0) {
                        nn-=sum;
                        printf("%d%d%d%d ", i1,i2,i3,i4);
                    }
                }
            }
        }
    }
    return 0;
}
