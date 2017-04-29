#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string *A = new string[n];
    for (int i=0; i<n; i++) cin >> A[i];
    
    vector<int> answer;
    for (int i=1; i <= n; i++) { 
        if (n%i!=0) continue;
        
        bool good = true;
        set<string> S;
        for (int j=0; j<n/i && good; j++) {
            string current = "unknown";
            for (int k=0; k<i; k++) {
                if (current == "unknown") {
                    if (A[j*i+k] != "unknown") {
                        current = A[j*i+k];
                        if (S.find(current) == S.end()) {
                            S.insert(current);
                        } else {
                            good = false;
                            break;
                        }
                    }
                } else if(A[j*i+k] != "unknown" && A[j*i+k]!=current) {
                    good = false;
                    break;
                }
            }
        }
        if (good) {
            answer.push_back(n/i);
        }
    }
    if (answer.size()==0) {
        printf("Igor is wrong.");
    } else {
        for (int i=answer.size()-1; i>=0; i--) {
            printf("%d ", answer[i]);
        }
    }
    return 0;
}