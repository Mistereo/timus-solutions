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
    int n,p;
    scanf("%d%d", &n, &p);
    int *A = new int[n];
    for (int i=0; i<n; i++)
        scanf("%d", A+i);
    sort(A, A+n);
    vector< pair<int, int> > B;
    B.push_back(make_pair(A[0], 1));
    for (int i=1; i<n; i++) {
        int pos = (int)B.size()-1;
        if (A[i] == B[pos].first) {
            B[pos].second++;
        } else {
            B.push_back(make_pair(A[i], 1));
        }
    }
    int cnt = 0;
    int answer = 0;
    int steps = 0;
    for (int i=0; i<B.size(); i++) {
        if (cnt * B[i].first +
            B[i].second * B[i].first <= p) {
            cnt += B[i].second;
        } else {
            if (cnt == 0) {
                break;
            }
            answer += cnt;
            cnt = 0;
            i--;
            steps++;
        }
    }
    if (cnt) {
        steps++;
        answer+=cnt;
    }
    printf("%d %d", answer, steps);
    return 0;
}