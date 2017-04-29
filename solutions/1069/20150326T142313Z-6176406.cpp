#define TASK T1069

#pragma ide diagnostic ignored "OCUnusedMacroInspection"
#pragma ide diagnostic ignored "UnusedImportStatement"
#define _USE_MATH_DEFINES

#define INF int(1e9)
#define EPS 1e-9

#define int64 long long
#define uint64 unsigned long long
#define var auto
#define mp make_pair

#define W first
#define H second

#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <list>
#include <ctime>
#include <cstring>

using namespace std;

class T1069 {
public:
    vector<int> A;
    vector< vector<int> > G;
    vector<bool> USED;
    vector<int> COUNT;
    void addEdge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    TASK() {
        int a;
        while (scanf("%d", &a) != EOF) {
            A.push_back(a - 1);
        }
        G.assign(A.size() + 1, vector<int>());
        USED.assign(A.size() + 1, false);
        COUNT.assign(A.size() + 1, 0);
        int mn = 0;
        for (int i=0; i<A.size(); i++) {
            COUNT[A[i]]++;
        }
        for (int i=0; i<A.size(); i++) {
            while (COUNT[mn] != 0 || USED[mn] == true) mn++;
            
            USED[mn] = true;
            addEdge(mn++, A[i]);
            
            COUNT[A[i]]--;
            
            if (COUNT[A[i]] == 0) {
                mn = min(mn, A[i]);
            }
        }
        for (int i=0; i<G.size(); i++) {
            printf("%d: ", i + 1);
            sort(G[i].begin(), G[i].end());
            for (int j=0; j<G[i].size(); j++) {
                printf("%d ", G[i][j] + 1);
            }
            printf("\n");
        }
    }
};

int main(int argc, const char * argv[]) {
#ifdef MISTMAC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    new TASK();
    return 0;
}