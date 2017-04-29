#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int const MSIZE = 140;
int main() {
    int n;
    scanf("%d", &n);
    bool trochee = 1, iamb = 1, dactyl = 1, amphibrach = 1, anapest = 1; 
    for (int i=0; i<n; i++) {
        string line = "";
        while (!line.size()) {
            getline(cin, line);
        }
        for (string::iterator it = line.begin(); it != line.end(); it++) {
            if (*it == '-') *it = ' ';
        }
        
        istringstream poem(line);
        
        vector<bool> mask;
        while (poem >> line) {
            if (line[0] == '[') mask.push_back(1);
            else mask.push_back(0);
        }

        for (int i=0; i < (mask.size()/2)*2 && (iamb || trochee); i+=2) {
            if (mask[i] != 1 || mask[i+1] != 0) {
                trochee = 0;
            }
            if (mask[i] != 0 || mask[i+1] != 1) {
                iamb = 0;
            }
        }
        if ((mask.size()/2)*2 < mask.size() && (iamb || trochee)) {
            if (mask[mask.size()-1] != 1) {
                trochee = 0;
            }
            if (mask[mask.size()-1] != 0) {
                iamb = 0;
            }
        }
        for (int i=0; i < (mask.size()/3)*3 && (dactyl || amphibrach || anapest); i+=3) {
            if (mask[i] != 1 || mask[i+1] != 0 || mask[i+2] != 0) {
                dactyl = 0;
            }
            if (mask[i] != 0 || mask[i+1] != 1 || mask[i+2] != 0) {
                amphibrach = 0;
            }
            if (mask[i] != 0 || mask[i+1] != 0 || mask[i+2] != 1) {
                anapest = 0;
            }
        }
        if (mask.size() - (mask.size()/3)*3 == 1 && (dactyl || amphibrach || anapest)) {
            if (mask[mask.size()-1] != 1) {
                dactyl = 0;
            }
            if (mask[mask.size()-1] != 0) {
                amphibrach = 0;
                anapest = 0;
            }
        }
        if (mask.size() - (mask.size()/3)*3 == 2 && (dactyl || amphibrach || anapest)) {
            if (mask[mask.size()-2] != 1 || mask[mask.size()-1] != 0) {
                dactyl = 0;
                
            }
            if (mask[mask.size()-2] != 0) {
                amphibrach = 0;
                anapest = 0;
            }
            if (mask[mask.size()-1] != 1) {
                amphibrach = 0;
            }
            if (mask[mask.size()-1] != 0) {
                anapest = 0;
            }
        }
    }
    if (trochee) printf("trochee");
    else if (iamb) printf("iamb");
    else if(dactyl) printf("dactyl");
    else if(amphibrach) printf("amphibrach");
    else if(anapest) printf("anapaest");
    else printf("not a poem");
    
    return 0;
}