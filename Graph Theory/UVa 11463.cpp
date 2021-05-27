/*
	UVa 11463 - Commandos

	In this problem I used double bfs from the starting and the ending node
	and later added their levels
	and printed the maximum of those addition of the levels

*/
#include <bits/stdc++.h>

using namespace std;

int n, m, farthest;

unordered_map < int , vector< int > > edges;
bool vis[107];
int lvl[107], lvl_2[107];

void initiate(int x){
	if(x==1) edges.clear();
	memset(vis, false, sizeof(vis));
	if(x==1) memset(lvl, 0, sizeof(lvl));
	if(x==1) memset(lvl_2, 0, sizeof(lvl_2));
	farthest = 0;
}

void bfs(int source){
	queue < int > Q;
	Q.push(source);
	lvl[source] = 0;
	vis[source] = true;
	while(!Q.empty()){
		m = Q.front();
		Q.pop();
		for(auto child: edges[m]){
			if(!vis[child]){
				vis[child] = true;
				lvl[child] = lvl[m] + 1;
				Q.push(child);
			}
			else{
				lvl[child] = min( lvl[m] + 1, lvl[child]);
			}
		}
	}
}

void bfs1(int source){
	queue < int > Q;
	Q.push(source);
	lvl_2[source] = 0;
	vis[source] = true;
	while(!Q.empty()){
		m = Q.front();
		Q.pop();
		for(auto child: edges[m]){
			if(!vis[child]){
				vis[child] = true;
				lvl_2[child] = lvl_2[m] + 1;
				Q.push(child);
			}
			else{
				lvl_2[child] = min( lvl_2[m] + 1, lvl_2[child]);
			}
		}
	}
}

int getAns(){
	for(int i=0;i<n;i++){
		if(farthest < lvl[i] + lvl_2[i]) farthest = lvl[i] + lvl_2[i];
	}
	return farthest;
}

int main(){

	int t, u, v, cs = 1;
	cin >> t;

	while(t--){
		
		cin >> n >> m;
		
		initiate(1);

		while(m--){
			cin >> u >> v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}

		cin >> u >> v;

		bfs(u);
		
		initiate(0);
		bfs1(v);

		cout << "Case " << cs++ << ": " << getAns() << endl;
	}

	return 0;
}
