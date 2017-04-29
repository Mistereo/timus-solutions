#include <iostream>
#include <set>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int x = 0,y = 0;
	int xx = 0, yy = 0;
    long double root = 0.707106781186547524400844362104849039284;
    string s;
    cin >> s;
    for (int i=0; i<s.size(); i++) {
        if (s[i]=='0') {
            break;
        } else if (s[i]=='1') {
			yy--;
			xx--;
        }
        else if (s[i]=='2') {
            y--;
        }
        else if (s[i]=='3') {
			xx++;
			yy--;
        }
        else if (s[i]=='4') {
            x--;
        }
        else if (s[i]=='6') {
            x++;
        }
        else if (s[i]=='7') {
			yy++;
			xx--;
        }
        else if (s[i]=='8') {
            y++;
        }
        else if (s[i]=='9') {
			yy++;
			xx++;
        }
    }
    printf("%.10Lf %.10Lf", (long double)(root*xx+x),(long double)(root*yy+y));
    return 0;
}