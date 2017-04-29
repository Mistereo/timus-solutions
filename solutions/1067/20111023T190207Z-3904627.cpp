#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

struct dir {
    map<string, dir> childs;
};
void print(dir cur, string indent = "") {
    for (map<string, dir>::iterator it = cur.childs.begin(); it!=cur.childs.end(); it++) {
        printf("%s%s\n", indent.c_str(), it->first.c_str());
        print(it->second, indent + " ");
    }
}
int main() {
    int n;
    string str;
    scanf("%d", &n);
    getline(cin, str);
    dir root;
    for (int i=0; i<n; i++) {
        getline(cin, str);
        replace(str.begin(), str.end(), '\\', ' ');
        stringstream tmp(str);
        string p, s;
        tmp >> p;
        dir *cur = &root.childs[p];
        while(tmp >> s) {
            cur->childs[s];
            cur = &cur->childs[s];
        }
    }
    for (map<string, dir>::iterator it = root.childs.begin(); it!=root.childs.end(); it++) 
    {
        printf("%s\n", it->first.c_str());
        print(it->second, " ");
    }
    return 0;
}