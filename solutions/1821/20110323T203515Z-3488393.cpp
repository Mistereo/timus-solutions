#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



struct biat{
	int res;
	string name;
	int time;
};
int time(int n, int s, int d, int i=0){
	return ((n+(s+i*30)/60)*1000)  +  (((s+i*30)%60)*10)  +   d;
}
bool cmpT(biat a, biat b) {
	return a.time < b.time;
}
void main(){
	int n,m,s,d;
	string name;
	scanf("%d",&n);
	biat *a = new biat[n];
	//cout << time(21,10,5,3);
	//system("pause");
	for(int i=0; i<n; i++) {
		cin >> name;
		scanf("%d:%d.%d", &m,&s,&d);
		a[i].time=time(m,s,d,i);
		a[i].name=name;
		a[i].res=time(m,s,d);
	}
	sort(a,a+n,cmpT);
	vector<string> res;
	res.push_back(a[0].name);
	int min=a[0].res;
	for(int i=1; i<n; i++){
		if(a[i].res<min) {
			min = a[i].res;
			res.push_back(a[i].name);
		}
	}
	cout << res.size() << endl;
	sort(res.begin(),res.end());
	for(int i=0; i<res.size(); i++)
		cout << res[i] << endl;

	system("pause");
}