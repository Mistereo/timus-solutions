#ifndef ONLINE_JUDGE
#include <ctime>
#endif

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <sstream>
#include <cmath>
#include <time.h>

#define pb push_back
#define mp make_pair
#define int64 long long
#define int16 short
using namespace std;

struct client {
    int amount;
    string name;
};

vector<client> Clients;

int main (int argc, const char * argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    clock_t startTime = clock();
#endif
    //------------------------------------------
    int n; scanf("%d", &n);
    map<string, int> M;
    for (int i=0; i<n; i++) {
        int amount;
        string name;
        cin >> amount >> name >> name;
        M[name] = amount;
    }
    int m; scanf("%d", &m);
    int ind = 0;
    for (int i=0; i<m; i++) {
        int a;
        string name;
        cin >> a >> name >> name;
        client x = {a,name};
        Clients.push_back(x);
    }
    client asd = {0,"mark-mark"};
    Clients.push_back(asd);
    int answer = 0;
    while (ind < m) {
        if (Clients[ind].name == "mark-mark") {
            printf("%d", answer);
            exit(0);
        }
        //for (int i=ind; i<m; i++) {
        //    printf("%d %s\n", Clients[i].amount, Clients[i].name.c_str());
        //}
        //printf("-----------------\n");
        int a = Clients[ind].amount;
        string name = Clients[ind].name;
        auto it = M.find(name);
        //printf("%d\n", it->second);
        if (it==M.end() || it->second == 0) {
            ind++;
        } else {
            if (it->second >= a) {
                it->second-=a;
                ind++;
            } else {
                Clients[ind].amount = it->second;
                swap(Clients[ind],Clients[ind+1]);
            }
        }
        answer++;
    }
    printf("%d", answer);
    //------------------------------------------
#ifndef ONLINE_JUDGE
    clock_t endTime = clock();
    printf("\n%lf", double(endTime-startTime)/CLOCKS_PER_SEC);
    fclose(stdout);
#endif
    return 0;
}