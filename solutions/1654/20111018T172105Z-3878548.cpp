#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

double const epsilon = 1e-6;

int main() {
    string  str;
    cin >> str;
    stack<char> st;
    for (int i=str.size()-1; i>=0; i--) {
        if (st.empty()) {
            st.push(str[i]);
        } else if(st.top() == str[i]) {
            st.pop();
        } else {
            st.push(str[i]);
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}