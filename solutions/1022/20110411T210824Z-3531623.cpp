#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector< vector< int > > g;
vector< bool > used;
vector< int > tops;
void dfs(int v){
	used[v]=true;
	for(vector<int>::iterator i=g[v].begin(); i!=g[v].end(); i++) {
		if(!used[*i])
			dfs(*i);
	}
	tops.push_back(v);
}
void topSort() {
	for(int i=0; i<n; i++) {
		if(!used[i])
			dfs(i);
	}
}
int main() {
	int x;
	scanf("%d",&n);
	used.assign(n,false);
	g.resize(n);
	for(int i=0; i<n; i++) {
		scanf("%d",&x);
		while(x!=0) {
			g[i].push_back(x-1);
			scanf("%d",&x);
		}
	}
	topSort();
	for(vector<int>::reverse_iterator i=tops.rbegin(); i!=tops.rend(); i++)
		printf("%d ",*i+1);
	system("pause");
	return 0;
}