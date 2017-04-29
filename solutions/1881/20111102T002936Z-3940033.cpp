//1881
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main (int argc, const char * argv[])
{
    int h,w,n;
    scanf("%d%d%d", &h, &w, &n);
    string str;
    
    int linesCount = 0;
    int curLine = -1;
    for (int i=0; i<n; i++) {
        cin >> str;
        if (curLine + str.size()+1 <= w) {
            curLine += str.size()+1;
            //cout << curLine << " ";
        }
        else {
            curLine = (int)str.size();
            linesCount++;
        }
    }
    linesCount++;
    printf("%d", (linesCount+h-1)/h);
    
    return 0;
}