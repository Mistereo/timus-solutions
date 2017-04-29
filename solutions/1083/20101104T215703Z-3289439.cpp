#include <iostream>
#include <string>
void main(){int n;std::string str;std::cin>>n>>str;int k=str.length();int nk=n;int x=1;while(n-k*x>0){nk*=(n-k*x);x++;}std::cout<<nk;}