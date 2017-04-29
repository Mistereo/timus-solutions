#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	string s;
	char c='0';
	int asd=scanf("%c",&c);
	while(asd!=EOF) {
		if((c>='a' && c<= 'z') || (c>='A' && c<= 'Z'))
			s+=c;
		else {
			cout << string(s.rbegin(),s.rend()) << c;
			s="";
		}
		asd = scanf("%c",&c);
	}
	cout << string(s.rbegin(),s.rend());
	return 0;
}