#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> N;
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        N.insert(x);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        N.insert(x);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        N.insert(x);
    }
    int x = *N.begin();
    int count = 1;
    int ans = 0;
    for (multiset<int>::iterator it=++N.begin(); it!=N.end(); it++) {
        if(x == *it) {
            count++;
            if(count == 3) {
                ans++;
            }
        } else {
            x = *it;
            count=1;
        }
    }
    printf("%d" ,ans);
    return 0;
}