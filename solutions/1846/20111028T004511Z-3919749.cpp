#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000;
int n;
int iter = 1;
int gcd(int a, int b) {
    while (b!=0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
map<int, pair<int/*index*/, int/*count*/> > M;
struct gcdTree {
    int *tree;
    gcdTree(int n) {
        tree = new int[4*n];
        fill(tree, tree+4*n, 0);
    }
    int getGCD() {
        return tree[1];
    }
    void ins(int value, int index, int cur = 1, int left = 0, int right = n-1) {
        if (left == right) {
            tree[cur] = value;
        } else {
            int midle = (left+right)/2;
            if (index <= midle) {
                ins(value, index, cur*2, left, midle);
            } else {
                ins(value, index, cur*2+1, midle+1, right);
            }
            tree[cur] = gcd(tree[cur*2], tree[cur*2+1]);
        }
    }
    void del(int index) {
        ins(0, index);
    }
};

int main() {
    scanf("%d", &n);
    gcdTree tree(n);
    for (int i=0; i<n; i++) {
        char c;
        int elem;
        cin >> c >> elem;
        if (c == '+') {
            if (M.find(elem)!=M.end()) {
                if (M[elem].second == 0)
                    tree.ins(elem, M[elem].first);
                M[elem].second++;
            } else {
                M[elem] = make_pair(iter, 1);
                tree.ins(elem, iter);
                iter++;
            }
            printf("%d\n", tree.getGCD() ? tree.getGCD() : 1);
        } else {
            if (--M[elem].second == 0) {
                tree.del(M[elem].first);
            }
            printf("%d\n", tree.getGCD() ? tree.getGCD() : 1);
        }
    }
    return 0;
}