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

string temp;
int cnt = 0;

class Tree {
    bool term;
    map<char, Tree*> dict;
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
    void dfs(Tree *v) {
        if (cnt==20) {
            return;
        }
        if (v->term) {
            cnt++;
            cout << "  " << temp << "\n";
        }
        for (auto i=v->dict.begin(); i!=v->dict.end(); i++) {
            temp.push_back(toChar(i->first));
            dfs(v->dict[i->first]);
            temp.pop_back();
        }
    }
public:
    Tree() {
        term = false;
    }
    void add(string s) {
        Tree *cur = this;
        for (int i=0; i<s.size(); i++) {
            int id = ind(s[i]);
            
            if (cur->dict.find(id) != cur->dict.end() ) {
                cur = cur->dict[ id ];
            } else {
                cur->dict[ id ] = new Tree();
                cur = cur->dict[ id ]; 
            }
        }
        cur->term = true;
    }
    void search(string s) {
        temp = s;
        cnt = 0;
        Tree *cur = this;
        for (int i=0; i<s.size(); i++) {
            int id = ind(s[i]);
            if (cur->dict.find(id) != cur->dict.end() ) {
                cur = cur->dict[ id ];
            } else {
                return;
            }
        }
        dfs(cur);
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
        }
    }
    //--------------------------------------
#ifdef MISTMAC
	fclose(stdout); fclose(stdin);
#endif
    return 0;
}