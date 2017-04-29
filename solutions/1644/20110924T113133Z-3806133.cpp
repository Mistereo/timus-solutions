#include <iostream>
#include <string>
using namespace std;
string str;

int main (int argc, const char * argv[])
{    
    int n,tmp,h = 2,s = 10;
    string str;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        cin >> tmp >> str;
        if (str == "hungry") {
            if (tmp > h) h = tmp;
        } else {
            if (tmp < s) s = tmp;
        }
    }
    if (s <= h) printf("Inconsistent");
    else printf("%d", s);
}
