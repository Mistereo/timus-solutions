#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n, index=0;
    int in1, in2, in3;
    map<string, int> M;
    //M["Isenbaev"] = 0;
    scanf("%d", &n);
    int **A = new int*[n*3];
    for (int i=0; i<n*3; i++) {
        A[i] = new int[n*3];
        for (int j=0; j<n*3; j++) {
            A[i][j] = 10000;
        }
        A[i][i] = 0;
    }
    string n1,n2,n3;
    for (int i=0; i<n; i++) {
        cin >> n1 >> n2 >> n3;
        if (M.find(n1) == M.end()) {
            M[n1] = index;
            in1 = index;
            index++;
        } else {
            in1 = M[n1];
        }
        if (M.find(n2) == M.end()) {
            M[n2] = index;
            in2 = index;
            index++;
        } else {
            in2 = M[n2];
        }
        if (M.find(n3) == M.end()) {
            M[n3] = index;
            in3 = index;
            index++;
        } else {
            in3 = M[n3];
        }
        A[in1][in2] = 1;
        A[in2][in1] = 1;
        
        A[in1][in3] = 1;
        A[in3][in1] = 1;
        
        A[in2][in3] = 1;
        A[in3][in2] = 1;
    }
    for (int i=0; i<index; i++) {
        for (int j=0; j<index; j++) {
            for (int k=0; k<index; k++) {
                A[j][k] = min(A[j][k], A[j][i]+A[i][k]);
            }
        }
    }
    bool isenbaev = M.find("Isenbaev") != M.end();
    for (map<string,int>::iterator it = M.begin(); it!=M.end(); it++) {
        int result = isenbaev ? A[M["Isenbaev"]][M[it->first]] : 10000;
        
        if (result < 10000) {
            printf("%s %d\n", it->first.c_str(), result);
        } else {
            printf("%s undefined\n", it->first.c_str());
        }
    }
	return 0;
}
