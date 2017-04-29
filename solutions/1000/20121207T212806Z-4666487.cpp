#define _USE_MATH_DEFINES
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <map>
#include <cstdio>
#include <stack>
#include <iostream>
#include <queue>
#include <climits>
#include <bitset>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <deque>
#include <iomanip>
#include <cmath>

using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep (i,n) for(int i=n-1; i>=0; i--)
#define int64 long long
#define uint64 unsigned int64



int main (int argc, const char * argv[])
{
#ifdef MISTMAC
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    //--------------------------------------
    
    int a, b;
    scanf("%d%d", &a, &b);
    
    assert(a);
    assert(b);
    printf("%d", a+b);
    
    //--------------------------------------
#ifdef MISTMAC
	fclose(stdout);
	fclose(stdin);
#endif
    return 0;
}