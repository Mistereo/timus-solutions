#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Billionaire {
    long long status;
    string town;
    Billionaire() {}
    Billionaire(long long status, string town):status(status),town(town) {}
};
struct Town {
    long long status;
    Town(){ status = 0; };
    void operator+=(long long a) {
        status+=a;
    }
};

map<string /* name */, Billionaire> B;
map<string /* town */, Town> T;
map<string /* town */, int> C;
set<pair<long long /* status */, string /* town */> > ASD;

int main (int argc, const char * argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char name[21];
        char town[21];
        long long status;
        scanf("%s%s%lld", name, town, &status);
        auto *curTown = &T[town];
        curTown->status += status;
        if (curTown->status == status) {
            ASD.insert(make_pair(status, town));
        } else {
            ASD.erase(make_pair(curTown->status - status, town));
            ASD.insert(make_pair(curTown->status, town));
        }
        B[name] = Billionaire(status, string(town));
    }
    int currentDay = 0;
    int days, k;
    scanf("%d%d", &days, &k);
    for (int i=0; i<k; i++) {
        int day;
        char name[21], town[21];
        scanf("%d%s%s", &day, name, town);
        if (day!=currentDay) {
            long long mx = 0;
            long long tmp = 0;
            
            string mxTown = "";
            
            auto it = ASD.end();
            it--;
            
            if (ASD.size()>1) {
                mx = it->first;
                mxTown = it->second;
                it--;
                tmp = it->first;
            } else {
                mx = it->first;
                mxTown = it->second;
            }
            
            if (tmp != mx) {
                C[mxTown]+=(day-currentDay);
            }
            currentDay = day;
        }
        auto *curBill = &B[name];
        auto *fromTown = &T[curBill->town];
        auto *toTown = &T[town];
        ASD.erase(make_pair(fromTown->status, curBill->town));
        fromTown->status -= curBill->status;
        ASD.insert(make_pair(fromTown->status, curBill->town));
        
        curBill->town = town;
        
        ASD.erase(make_pair(toTown->status, curBill->town));
        toTown->status += curBill->status;
        ASD.insert(make_pair(toTown->status, curBill->town));
    }
    long long mx = 0;
    long long tmp = 0;
    
    string mxTown = "";
    
    auto it = ASD.end();
    it--;
    
    if (ASD.size()>1) {
        mx = it->first;
        mxTown = it->second;
        it--;
        tmp = it->first;
    } else {
        mx = it->first;
        mxTown = it->second;
    }
    if (tmp != mx) {
        C[mxTown]+=(days-currentDay);
    }
    for (auto it = C.begin(); it!=C.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }
    return 0;
}