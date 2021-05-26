/*
	CodeForces 1106D - Lunar New Year and a Wander

	simple bfs just use set / reverse priority queue in stead of the bfs queue

*/
#include <bits/stdc++.h>

using namespace std;

map < int , vector< int > > edges;
vector < int > ans;
bool vis[100007];

void initiate(int n){
	edges.clear();
	ans.clear();
	memset(vis, false, sizeof(vis));
}

void bfs(){
	set < int > st;
	st.insert(1);
	vis[1] = true;
	while(st.size() > 0){
		auto x = *st.begin();
		ans.push_back(x);
		st.erase(x);
		for(auto child: edges[x]){
			if(!vis[child]){
				vis[child] = true;
				st.insert(child);
			}
		}
	}
}

int main(){

	int t, n, m, u, v;
	cin >> n >> m;
		
	initiate(n);

	while(m--){
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	bfs();

	for(auto lol : ans) cout << lol << " ";
	cout << endl;

	return 0;
}
