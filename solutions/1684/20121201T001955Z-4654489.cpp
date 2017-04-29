#define _USE_MATH_DEFINES
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define mp make_pair
#define pb push_back
#define int64 long long
#define uint64 unsigned long long

vector<int> Z(string S) {
    int n = (int)S.size();
    vector<int> z(n);
    z[0] = 0;
    int l = 0;
    int r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r) {
            z[i] = min(z[i-l], r-i+1);
        } else {
            z[i] = 0;
        }
        while (i+z[i] < S.size() && S[z[i]] == S[i+z[i]])
            z[i]++;
        if (i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string S, P;
    cin >> S >> P;
    string SS = S;
    SS+='#';
    SS+=P;
    vector<int> z = Z(SS);
    
    z.assign(z.begin()+S.size()+1, z.end());
    z.push_back(1000000000);
    
    int l = 0;
    int r = 0;
    vector<string> ans;
    for (int i=0; i<P.size()+1; i++) {
        if (r < i) {
            printf("Yes\n");
            return 0;
        }
        if (i+z[i] <= r) {
                
        } else {
            ans.push_back(string(P.begin()+l, P.begin()+i));
            l = i;
            r = i+z[i];
        }
    }
    printf("No\n");
    for (int i=0; i<ans.size(); i++) {
        if(ans[i].size()!=0)
            printf("%s ",ans[i].c_str());
    }
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}