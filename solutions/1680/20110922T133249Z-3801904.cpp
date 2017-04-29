//
//  main.cpp
//  acm
//
//  Created by Mistereo on 20.09.11.
//  Copyright 2011 УрФУ. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct team {
    team(string n, string nn) {
        name = n;
        num = nn;
    }
    string name;
    string num;
};

string toUp(string s) {
    for (string::iterator it = s.begin(); it!=s.end();it++) {
        *it = toupper(*it);
    }
    return s;
}

team getTeam(string s) {
    string name = "";
    string num = "";
    int x=0;
    for (string::iterator it = s.begin(); it!=s.end() && *it!='#'; it++, x++) {
        name+=*it;
    }
    num = s.substr(x,s.length()-1);
    return team(name,num);
}

int main (int argc, const char * argv[])
{
    vector<team> v;
    int q, n;
    string str;
    cin >> q >> n >> q;
    
    getline(cin, str);
    bool x = false;
    for (int i=0; i<n; i++) {
        getline(cin, str);
        team t = getTeam(str);
        for (vector<team>::iterator it=v.begin(); it!=v.end(); it++) {
            //cout << "'" << t.name << "'" << "' " << it->name << "'" << endl;
            if (toUp(t.name) == toUp(it->name)) {
                x = true;
                break;
            }
        }
        if (!x) {
            if (q==0) {
                cout << t.name << t.num;
                break;
            } else {
                q--;
                v.push_back(t);
            }
        }
        x = false;
    }
    
    return 0;
}