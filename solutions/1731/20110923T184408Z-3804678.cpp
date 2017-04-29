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
    
    int n,m;
    scanf("%d%d", &n,&m);
    
    for (int i=0; i<n; i++)
        cout << i + 1 << " ";
    cout << endl;
    for (int i=0; i<m; i++)
        cout << (i + 1) * 100 << " ";
    return 0;
}
