#define _USE_MATH_DEFINES
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#define mp make_pair
#define pb push_back
#define int64 long long
#define uint64 unsigned long long
int cent = 0;
class SA {
    struct State {
        State() {
            n = cent++;
        }
        int n;
        int len;
        State *link;
        map<char, State*> next;
        int cnt() {
            int res = 0;
            for (auto it=next.begin(); it!=next.end(); it++) {
                res += it->second->cnt();
            }
            return res + 1;
        }
        void print(int t = 0) {
            for(auto it=next.begin(); it!=next.end(); it++){
                for (int i=0; i<t; i++) {
                    printf(" ");
                }
                printf("%c(%d)", it->first, n);
                printf("\n");
                it->second->print(t+1);
            }
        }
    };
    State *root;
    State *last;
public:
    SA() {
        root = new State();
        last = root;
        root->len = 0;
        root->link = NULL;
    }
    void extend(char c) {
        State *cur = new State();
        cur->len = last->len + 1;
        State *p = last;
        while (p!=NULL && !p->next.count(c)) {
            p->next[c] = cur;
            p = p->link;
        }
        if (p == NULL) {
            cur->link = root;
        } else {
            State *q = p->next[c];
            if (p->len+1 == q->len) {
                cur->link = q;
            } else {
                State *clone = new State();
                clone->len = p->len + 1;
                clone->next = q->next;
                clone->link = q->link;
                while (p!=NULL && p->next[c]==q) {
                    p->next[c] = clone;
                    p = p->link;
                }
                q->link = clone;
                cur->link = clone;
            }
        }
        last = cur;
    }
    int count() {
        return root->cnt();
    }
    void print() {
        root->print();
    }
};


int main() {
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    SA *S = new SA();
    char c;
    while (scanf("%c",&c)!=EOF) {
        if ('a' <= c && c <= 'z') {
            S->extend(c);
        }
    }
    
    printf("%d", S->count()-1);
    
#ifdef MISTMAC
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}