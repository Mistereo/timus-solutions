#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main() {
	string 
		s="",
		cmp="qwertyuiopasdfghjklzxcvbnm";
	int tramc=0,trolc=0;
	//int pos=0;
	//while(!cin.eof() && st!="qqq") {
	//	cin >> st;
	//	s.append(st);
	//	s.push_back(' ');
	//}
	while(!cin.eof() && s!="qqq") {
		cin >> s;
		if(s.find("tram",0)!=string::npos) {
			if(s.length()>4) {
				if(cmp.find(s[4],0)==string::npos)
					tramc++;
			} else
				tramc++;
		}
		if(s.find("trolleybus",0)!=string::npos) {
			if(s.length()>10) {
				if(cmp.find(s[10],0)==string::npos)
					trolc++;
			} else
				trolc++;
		}
	}
	cout << endl;
	if(tramc==trolc)
		cout << "Bus driver";
	else if(trolc>tramc)
		cout << "Trolleybus driver";
	else
		cout << "Tram driver";
	system("pause");
}