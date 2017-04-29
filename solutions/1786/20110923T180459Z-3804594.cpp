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
    int res = 20;
    string sandro = "Sandro";
    for(int i = 0; i <= str.length() - sandro.length(); i++){
        int count = 0;
        for(int j = 0; j < sandro.length(); j++){
            char s1 = sandro[j];
            char s2 = str[j+i];
            if(s1 != s2)
                if((s1 <= 'z' && s1 >= 'a' && s2 <= 'z' && s2 >= 'a') || 
                   (s1 <= 'Z' && s1 >= 'A' && s2 <= 'Z' && s2 >= 'A'))
                    count++;
                else if (toupper(s1) == toupper(s2))
                    count++;
                else 
                    count+=2;
        }
        if(count < res)
            res = count;
    }
    cout << ((res == 20) ? 0 : res*5);
    return 0;
}
