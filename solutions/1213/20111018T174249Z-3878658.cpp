#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    set<string> S;
    string str;
    cin >> str;
    S.insert(str);
    getline(cin, str);
    while (true) {
        string s1;
        char c;
        scanf("%c", &c);
        if (c=='#') {
            break;
        }
        getline(cin, s1, '-');
        s1=c+s1;
        S.insert(s1);
        getline(cin, s1);
        S.insert(s1);
        
    }
    cout << S.size() - 1;
    return 0;
}