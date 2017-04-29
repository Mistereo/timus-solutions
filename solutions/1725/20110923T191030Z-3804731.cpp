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
#include <algorithm>

using namespace std;

int main (int argc, const char * argv[])
{    
    int n,k;
    scanf("%d%d", &n, &k);
    
    printf("%d", n > 3 ? max(n-k,k-1)-2 : 0);
    return 0;
}
