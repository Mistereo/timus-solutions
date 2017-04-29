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

int decode(int y, int of = 0) {
    int x = (y - 5 - of + 26) % 26;
    return x < 0 ? (x + 26) : x;
}

using namespace std;

int main (int argc, const char * argv[])
{
    
    string str;
    cin >> str;
    int of = 0;
    for (int i=0; i<str.length(); i++) {
        int cur = decode(str[i] - 'a', of); 
        printf("%c", cur+'a');
        of+=cur;
    }
    
    return 0;
}

