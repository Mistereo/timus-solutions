#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    set<string> *A = new set<string>[n];
    vector<string> Names;
    for (int i=0; i<n; i++) {
        string tmp;
        cin >> tmp;
        Names.push_back(tmp);
        A[i].insert(tmp);
        cin >> tmp;
        Names.push_back(tmp);
        A[i].insert(tmp);
        cin >> tmp;
        Names.push_back(tmp);
        A[i].insert(tmp);
    }
    int *numbers = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &numbers[i]);
    }
    sort(Names.begin(), Names.end());
    vector<string> Res;
    int current = 0;
    for (int i=0; i<Names.size() && current < n; i++) {
        if (A[numbers[current]-1].find(Names[i]) != A[numbers[current]-1].end()) {
            current++;
            Res.push_back(Names[i]);
        }
    }
    if (current != n) {
        printf("IMPOSSIBLE");
    } else {
        for (int i=0; i<n; i++) {
            printf("%s\n", Res[i].c_str());
        }
    }
    return 0;
}