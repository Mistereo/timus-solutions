#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
float PI = atan(1.0f) * 4.0f;
bool f(pair<string, int> a, pair<string,int> b) {
    return a.second > b.second;
}
int main() {
    int n;
    scanf("%d", &n);
    vector< set<string> > team1;
    vector< set<string> > team2;
    vector< set<string> > team3;
    
    for (int i=0; i<n; i++) {
        string name;
        int x;
        scanf("%d", &x);
        if (x==3) {
            set<string> tmp;
            for (int j=0; j<3; j++) {
                cin >> name;
                tmp.insert(name);
            }
            team3.push_back(tmp);
        }
        if (x==2) {
            set<string> tmp;
            for (int j=0; j<2; j++) {
                cin >> name;
                tmp.insert(name);
            }
            team2.push_back(tmp);
        }
        if (x==1) {
            set<string> tmp;
            cin >> name;
            tmp.insert(name);
            team1.push_back(tmp);
        }
    }
    int re, rk, nn;
    scanf("%d%d%d", &re, &rk, &nn);
    vector< pair<string, int> > names;
    for (int i=0; i<nn; i++) {
        string name;
        int x;
        cin >> name >> x;
        names.push_back(pair<string, int>(name, x));
    }
    int mx = 0;
    string mname = "";
    sort(names.begin(), names.end(), f);
    for (int i=0; i<nn; i++) {
        bool test = true;
        for (int j=0; j<team3.size(); j++) {
            if (team3[j].find(names[i].first) != team3[j].end()) {
                test = false;
            }
        }
        if (test) {
            if (mx < names[i].second + rk + re) {
                mx = names[i].second + rk + re;
                mname = names[i].first;
            }
        }
        test = true;
        for (int j=0; j<team2.size(); j++) {
            if (team2[j].find(names[i].first) != team2[j].end()) {
                test = false;
            }
        }
        if (test) {
            if (mx < names[i].second + rk) {
                mx = names[i].second + rk;
                mname = names[i].first;
            }
        }
    }
    cout << ((mname == "") ? "Fail" : "Win\n" + mname);
    return 0;
}