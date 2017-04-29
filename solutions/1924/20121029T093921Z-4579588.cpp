#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <iostream>
#include <ctime>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
    int n; scanf("%d", &n);
    if (n%4==1 || n%4 == 2) {
        printf("grimy\n");
    } else {
        printf("black\n");
    }
	return 0;
}