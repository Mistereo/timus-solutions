#include <string>
#include <iostream>
using namespace std;
int main() {
int n;
char c;
scanf("%d",&n);
string* a = new string[n];
for(int i=0; i<n; i++) {
 cin >> a[i];
}
cin >> c;
for(int i=0; i<n; i++) {
 if(a[i][0]==c)
  cout << a[i] << endl;
}
return 0;
}