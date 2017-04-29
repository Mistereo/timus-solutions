//
//  main.cpp
//  timus
//
//  Created by Mistereo on 22.09.11.
//  Copyright 2011 USU. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <map>



using namespace std;

int main (int argc, const char * argv[])
{
    
    string str;
    cin >> str;
    int len = str.length(), max = 0;
    char res;
    for (int i=0; i<len; i++) {
        char cur = str[i];
        int count = 1;
        for (int j=i+1; j<len; j++) {
            if (str[j]==cur) count++;
        }
        if (count > max) {
            max = count;
            res = str[i];
        }
    }
    cout << res;
    return 0;
}
