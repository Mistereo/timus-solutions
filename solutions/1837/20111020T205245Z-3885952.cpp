#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <string>

const int INF = 1000000;

using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    map<string, int> M;
    int c = 0;
    
    vector< vector< pair<int, int> > > G(n*3);
    vector<bool> used(n*3);
    vector<int> d(n*3, INF);
    for (int i=0; i<n; i++) {
        string first, second, third;
        cin >> first >> second >> third;
        
        if (M.find(first) == M.end()) { M[first] = c; c++; }
        if (M.find(second) == M.end()) { M[second] = c; c++; }
        if (M.find(third) == M.end()) { M[third] = c; c++; }
        
        int fst = M[first], snd = M[second], trd = M[third];
        G[fst].push_back(make_pair(snd, 1));
        G[fst].push_back(make_pair(trd, 1));
        
        G[snd].push_back(make_pair(fst, 1));
        G[snd].push_back(make_pair(trd, 1));
        
        G[trd].push_back(make_pair(fst, 1));
        G[trd].push_back(make_pair(snd, 1));
    }
    
    if(M.find("Isenbaev") == M.end()) {
        for (map<string, int>::iterator it = M.begin(); it!=M.end(); it++) {
            printf("%s undefined\n", it->first.c_str());
        }
        return 0;
    }
    
    int start = M["Isenbaev"];
    d[start] = 0;
    
    for (int i=0; i<n*3; i++) {
        int v = -1;
        for (int j=0; j<n*3; j++) {
            if (!used[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INF) break;
        used[v] = true;
        
        for (int j=0; j<G[v].size(); j++) {
            int to = G[v][j].first;
            int weight = G[v][j].second;
            if (d[v] + weight < d[to]) {
                d[to] = d[v] + weight;
            }
        }
    }
    
    for (map<string, int>::iterator it = M.begin(); it!=M.end(); it++) {
        if(d[it->second] < INF) printf("%s %d\n", it->first.c_str(), d[it->second]);
        else printf("%s undefined\n", it->first.c_str());
    }
    return 0;
}