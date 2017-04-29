#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 2000000000
#define EPS 1e-9

int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n, mx;
    scanf("%d%d", &n, &mx);
    int *A = new int[n];
    for (int i=0; i<n; i++) {
        scanf("%d", A+i);
    }
    sort(A, A+n);
    reverse(A, A+n);
    
    vector<int> used;
    vector<int> answer;
    
    int left = 0;
    int right = n-1;
    while (left<=right) {
        if (right==left) {
            answer.push_back(A[right]);
            left++;
        } else if (A[left]+A[right]>mx) {
            answer.push_back(A[right]);
            answer.push_back(A[left]);
            left++; right--;
        } else {
            used.push_back(A[right]);
            right--;
        }
    }
    for (int i=(int)used.size()-1; i>=0; i--)
        answer.push_back(used[i]);
    
    int cnt = 0;
    answer.push_back(INF);
    for (int i=0; i<answer.size()-1; i++) {
        cnt++;
        if (answer[i]+answer[i+1] <= mx)
            i++;
    }
    printf("%d\n", cnt);
    for (int i=0; i<answer.size()-1; i++)
        printf("%d ", answer[i]);
    
    return 0;
}