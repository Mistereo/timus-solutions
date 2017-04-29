//
//  main.cpp
//  timus
//
//  Created by Mistereo on 22.09.11.
//  Copyright 2011 USU. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string str;
char *arr;
int slen;
void print() {
    for (int i=0; i<slen; i++) {
        cout << arr[i];
    }
    cout << endl;
}
void foo(char *beg, int len) {
    
    //print();
    
    if (len <= 0 || str.length() == 0) return;
    
    beg[(len+1)/2-1]=str[0];
    str = str.substr(1,str.length()-1);
    
    foo(beg, (len+1)/2-1);
    foo(beg+(len+1)/2, len-(len+1)/2);
}


int main (int argc, const char * argv[])
{
    
    getline(cin, str);
    slen = (int)str.length();
    arr = new char[slen];
    foo(arr,slen);
    print();
    return 0;
}
