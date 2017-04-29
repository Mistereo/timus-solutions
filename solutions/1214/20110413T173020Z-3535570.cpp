#include <iostream>
using namespace std;

int main(){
long long x, y;
cin >> x >> y;
if((x&1)!=(y&1) && x > 0 && y > 0)
swap(x,y);
cout << x << ' ' << y;
return 0;
}