/*
	UVa 1112 - Mice and Maze

	just dijkstra from all the node 
	and later check if the level of the exit node is less or equal to the time limit
	dont forget to check the cells that are not connected to the exit node at all

*/
#include <bits/stdc++.h>

using namespace std;

int n, m, e, T, u, v, x;

unordered_map < int , vector < pair < int , int > > > edges;

int lvl[107];
bool vis[107];

void dijkstra(int source){
	queue < int > Q;
	Q.push(source);
	lvl[source] = 0;
	vis[source] = true;
	while(!Q.empty()){
		x = Q.front();
		Q.pop();
		for(auto child: edges[x]){
			if(!vis[child.first]){
				vis[child.first] = true;
				lvl[child.first] = lvl[x] + child.second;
				Q.push(child.first);
			}
			else if(lvl[child.first] > lvl[x] + child.second){
				lvl[child.first] = lvl[x] + child.second;	
				Q.push(child.first);
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
		n = number of the cells 
		e = exit cell's index (1 based)
		T = time limit 
		m = number of edges
	*/

	int t, n, ans;
	cin >> t;

	while(t--){

		ans = 0;
		cin >> n >> e >> T >> m;
		
		while(m--){
			cin >> u >> v >> x;
			edges[u].push_back({v,x});
		}

		for(int i=1;i<=n;i++){
			memset(vis, false, sizeof(vis));
			memset(lvl, -1, sizeof(lvl));
			dijkstra(i);
			if(lvl[e] != -1 && lvl[e] <= T) ans++;
		}

		cout << ans << endl;
		if(t) cout << endl;

		edges.clear();
	}

	return 0;
}
