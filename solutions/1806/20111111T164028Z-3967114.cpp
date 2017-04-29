#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

const int INF = 1000000000;
int n;
vector<pair<int, int> > *G;
pair<string, int> *T;

void addToG(string s, int index, int xxx);
int binarySearch(int left, int right, string s);

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    int time[10];
    T = new pair<string, int>[n];
    for (int i=0; i<10; i++) scanf("%d", &time[i]);
    
    for (int i=0; i<n; i++) {
        char tmp[11];
        scanf("%s", tmp);
        T[i].first = tmp;
        T[i].second = i;
    }
    sort(T, T+n);
    G = new vector<pair<int, int> >[n];
    for (int i=0; i<n; i++) { 
        addToG(T[i].first, T[i].second, i);
    }
    
    int *d = new int[n];
    int *p = new int[n];
    fill(p, p+n, -1);
    fill(d, d+n, INF);
    d[0] = 0;
    set<pair<int, int> > S;
    S.insert(make_pair(d[0],0));
    
    while (!S.empty()) {
        
        
        int v = S.begin()->second;
        S.erase(S.begin());
        
        if (d[v] == INF) {
            break;
        }
        
        for (int i=0; i<G[v].size(); i++) {
            int to = G[v][i].first;
            int weight = time[(G[v][i].second)];
            if (d[v] + weight < d[to]) {
                S.erase(make_pair(d[to], to));
                d[to] = d[v] + time[(G[v][i].second)];
                p[to] = v;
                S.insert(make_pair(d[to], to));
            }
        }
    }
    
    if (d[n-1]==INF) {
        printf("-1");
        return 0;
    } else {
        vector<int> path;
        for (int i=n-1; i!=0; i=p[i]) path.push_back(i+1);
        path.push_back(1);
        printf("%d\n%d\n", d[n-1], (int)path.size());
        for (int i=(int)path.size()-1; i>=0; i--) printf("%d ", path[i]);
    }
    
    return 0;
}

void addToG(string s, int index, int xxx) {
    for (int i=0; i<10; i++) {
        char d = '0';
        for (int j=0; j<10; j++) {
            if ((d+j)!=s[i]) {
                string tmp = s;
                tmp[i] = d + j;
                int result = binarySearch(xxx + 1, n-1, tmp);
                if (result != -1) {
                    G[index].push_back(make_pair(result, i));
                    G[result].push_back(make_pair(index, i));
                }
            }
            if (i < j && s[i] != s[j]) {
                string tmp = s;
                char x = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = x;
                int result = binarySearch(xxx + 1, n-1, tmp);
                if (result != -1) {
                    G[index].push_back(make_pair(result, i));
                    G[result].push_back(make_pair(index, i));
                }
            }
        }
    }
}
int binarySearch(int left, int right, string s) {
    while (left < right) {
        int middle = (left+right)/2;
        if (s <= T[middle].first) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    if (T[right].first == s) {
        return T[right].second;
    } else {
        return -1;
    }
}