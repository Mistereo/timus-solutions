#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  long long n,k,h=0,x=1;
  scanf("%lld%lld",&n,&k);
  n--;
  while(n>0 && x<k) {
    n-=x;
    h++;
    x+=x;
  }
  printf("%lld",h+((n+k-1)/k));
  return 0;
}