#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    char c;
    scanf("%d%c", &n, &c);
    map<char, int> P,B,E;
    P['A'] = P['D'] = 0;
    B['A'] = B['F'] = 0;
    E['A'] = E['K'] = 0;
    E['C'] = E['D'] = E['G'] = E['H'] = 1;
    
    if (n < 3) {
        if (P.find(c)!=P.end()) {
            printf("window");
        } else {
            printf("aisle");
        }
    } else if (n < 21) {
        if (B.find(c)!=B.end()) {
            printf("window");
        } else {
            printf("aisle");
        }
    } else {
        if (E.find(c)!=E.end()) {
            if (E[c]) {
                printf("aisle");
            } else {
                printf("window");
            }
        } else {
            printf("neither");
        }
    }

    return 0;
}