#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 1000000000


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    
    vector<int> S;
    
    for (int i=0; i<n; i++) {
        int q;
        scanf("%d", &q);
        if (q == -1) {
            printf("%d\n", S[S.size()-1]);
            S.pop_back();
        } else if (q == 0) {
            if (S.size() < n-i) {
                S.insert(S.end(), S.begin(), S.end());
            }
        } else {
            S.push_back(q);
        }
    }
    
    return 0;
}