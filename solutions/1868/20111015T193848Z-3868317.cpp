#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    map<string, string> T;
    for (int i=0; i<4; i++) {
        string s;
        cin >> s;
        T[s] = "gold";
    }
    for (int i=0; i<4; i++) {
        string s;
        cin >> s;
        T[s] = "silver";
    }
    for (int i=0; i<4; i++) {
        string s;
        cin >> s;
        T[s] = "bronze";
    }
    int n;
    scanf("%d", &n);
    int max = 0;
    int count = 0;
    for (int i=0; i<n; i++) {
        int nn;
        int tmpCount = 0;
        scanf("%d", &nn);
        for (int j=0; j<nn; j++) {
            string team;
            char c;
            string medal;
            cin >> team >> c >> medal;
            //printf("%s '' %s\n", team.c_str(), medal.c_str());
            if (T[team] == medal) {
                tmpCount++;
            }
        }
        if (tmpCount > max) {
            max = tmpCount;
            count = 1;
        } else if(tmpCount == max) {
            count++;
        }
    }
    printf("%d", count*5);
    return 0;
}
