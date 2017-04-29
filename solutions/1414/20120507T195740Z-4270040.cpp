#include <string>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;
#define int64 int

vector<string> ans;


const int dictLength = 26+11;

class Tree {
    bool term;
    Tree *dict[dictLength];
    int ind(char a) {
        if (isalpha(a)) {
            return a-'a';
        } else {
            return a-'0' + 26;
        }
    }
    char toChar(int c) {
        if (c<26) {
            return c+'a';
        } else {
            return c-26+'0';
        }
    }
    void dfs(Tree *v, string s) {
        if (ans.size()==20) {
            return;
        }
        if (v->term) {
            ans.push_back(s);
        }
        for (int i=0; i<dictLength; i++) {
            if (v->dict[i]!=NULL) {
                dfs(v->dict[i], s+toChar(i));
            }
        }
    }
public:
    Tree() {
        term = false;
        for (int i=0; i<dictLength; i++) {
            dict[i] = NULL;
        }
    }
    void add(string s) {
        Tree *cur = this;
        for (int i=0; i<s.size(); i++) {
            int id = ind(s[i]);
            
            if (cur->dict[ id ] != NULL ) {
                cur = cur->dict[ id ];
            } else {
                cur->dict[ id ] = new Tree();
                cur = cur->dict[ id ]; 
            }
        }
        cur->term = true;
    }
    void search(string s) {
        ans.clear();
        Tree *cur = this;
        for (int i=0; i<s.size(); i++) {
            int id = ind(s[i]);
            if (cur->dict[ id ] != NULL ) {
                cur = cur->dict[ id ];
            } else {
                return;
            }
        }
        dfs(cur, s);
    }
};

int main (int argc, const char * argv[])
{
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin); freopen("output.txt", "wt", stdout);
#endif
    //--------------------------------------
    string s;
    Tree *root = new Tree();
    root->add("sun");
    while (cin >> s) {
        if (s[0] == '+') {
            root->add(s.substr(1));
        } else {
            string str = s.substr(1);
            printf("%s\n", str.c_str());
            root->search(str);
            for (int i=0; i<ans.size() && i<20; i++) {
                printf("  %s\n", ans[i].c_str());
            }
        }
    }
    //--------------------------------------
#ifdef MISTMAC
	fclose(stdout); fclose(stdin);
#endif
    return 0;
}
