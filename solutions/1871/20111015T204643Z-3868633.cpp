#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int const MSIZE = 140;
int main() {
    int n, nn, index = 0;
    scanf("%d", &n);
    int **A = new int*[n];
    bool **ABC = new bool*[n];
    for (int i=0; i<n; i++) {
        A[i] = new int[n];
        ABC[i] = new bool[n];
        for (int j=0; j<n; j++) {
            A[i][j] = 10000;
            ABC[i][j] = 0;
        }
        A[i][i] = 0;
    }
    string str, str2;
    string sender = "";
    map<string, int> M;
    map<int, string> M1;
    for (int i=0; i<n; i++) {
        cin >> str;
        int fromIndex, toIndex;
        if (M.find(str) == M.end()) {
            M[str] = index;
            fromIndex = index;
            M1[index] = str;
            index++;
        } else {
            fromIndex = M[str];
        }
        scanf("%d", &nn);
        for (int j=0; j<nn; j++) {
            cin >> str2;
            if (M.find(str2) == M.end()) {
                M[str2] = index;
                toIndex = index;
                M1[index] = str2;
                index++;
            } else {
                toIndex = M[str2];
            }
            A[fromIndex][toIndex] = (str.size()+6);
            ABC[fromIndex][toIndex] = 1;
        }
        sender = str;
    }
    /*
     cout << endl;
     for (int i=0; i<n; i++) {
     for (int j=0; j<n; j++) {
     cout << A[i][j] << " ";
     }
     cout << endl;
     }
     //*/
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    string message = "";
    while (message.size() <= 0) {
        getline(cin, message);
    }
    int count = 1;
    
    /*
     for (int i=0; i<n; i++) {
     for (int j=0; j<n; j++) {
     cout << A[i][j] << " ";
     }
     cout << endl;
     }
     //*/
    //cout << message.size() << endl;
    vector<string> RES;
    RES.push_back(M1[0]);
    bool *isChecked = new bool[n];
    memset(isChecked, 0, n);
    for (int i=0; i<n; i++) {
        //cout << i << ':' << A[0][i] - MSIZE + int(message.size()) <<  " ";
        if (A[0][i] + int(message.size()) < 141) {
            for (int j=1; j<n; j++) {
                if (!isChecked[j] && ABC[i][j]) {
                    isChecked[j] = 1;
                    count++;
                    RES.push_back(M1[j]);
                }
            }
        }
    }                                     
    cout << count << endl;
    for (int i=0; i<count; i++) {
        cout << RES[i] << endl;
    }
    return 0;
}