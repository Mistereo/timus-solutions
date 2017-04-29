#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct tree {
    int data;
    tree *left, *right;
    tree() {
        data = -1;
        left = NULL;
        right = NULL;
    }
    void add(int x) {
        if (data == -1) {
            data = x;
        } else if(x > data) {
            if (right == NULL) {
                right = new tree();
            }
            this->right->add(x);
        } else {
            if (left == NULL) {
                left = new tree();
            }
            this->left->add(x);
        }
    }
    void print(tree *T) {
        if (T->data == -1) {
            return;
        } else {
            if(T->right != NULL) print(T->right);
            if(T->left != NULL) print(T->left);
        }
        printf("%d ", T->data);
    }
};
int main() {
    int n;
    scanf("%d", &n);
    int *A = new int[n];
    tree T;
    for (int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i=n-1; i>=0; i--) {
        T.add(A[i]);
    }
    T.print(&T);
    
    return 0;
}