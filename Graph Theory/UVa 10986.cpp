/*
	UVa 10986 - Sending email

	Simple dijkstra from s to t
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair < int , long long > pii;

int n, m, u, v;
long long x, y, z;
unordered_map < int , vector < pii > > edges; 
long long lvl[20007];
bool vis[20007];

void initiate(){
	edges.clear();
	memset(lvl, -1, sizeof(lvl));
	memset(vis, false, sizeof(vis));
}

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

	int t, cs = 1;
	cin >> t;
	while(t--){
		
		cin >> n >> m >> u >> v;

		initiate();
		
		while(m--){
			cin >> x >> y >> z;
			edges[x].push_back({y,z});
			edges[y].push_back({x,z});
		}
		
		dijkstra(u);

		cout << "Case #" << cs++ << ": ";
		if(lvl[v] != -1) cout << lvl[v] << endl;
		else cout << "unreachable" << endl;
	}

	return 0;
}
