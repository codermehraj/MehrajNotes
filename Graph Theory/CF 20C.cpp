/*
	CodeForces 20C - Dijkstra?

	dijkstra using long long leveled priority queue -_-
	
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, u, v, x, cur;

unordered_map < int , vector < pair < int , int > > > edges;
vector < int > ansV;
pair < int , int > xx;

long long lvl[100007];
int priv[100007];
bool vis[100007];

void dijkstra(int source){
	priority_queue< pair < long long , int >, vector< pair< long long , int >>, greater<pair< long long , int > > > Q;
	Q.push({0,source});
	lvl[source] = 0;
	vis[source] = true;
	while(!Q.empty()){
		xx = Q.top();
		Q.pop();
		for(auto child: edges[xx.second]){
			if(!vis[child.first]){
				vis[child.first] = true;
				lvl[child.first] = lvl[xx.second] + child.second;
				Q.push({lvl[child.first],child.first});
				priv[child.first] = xx.second;
			}
			else if(lvl[child.first] > lvl[xx.second] + child.second){
				lvl[child.first] = lvl[xx.second] + child.second;	
				Q.push({lvl[child.first],child.first});
				priv[child.first] = xx.second;
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1, ans;

	while(t--){

		ans = 0;
		cin >> n >>  m;
		
		while(m--){
			cin >> u >> v >> x;
			edges[u].push_back({v,x});
			edges[v].push_back({u,x});
		}

		for(int i=1;i<=1;i++){
			memset(vis, false, sizeof(vis));
			memset(lvl, -1, sizeof(lvl));
			memset(priv, -1, sizeof(priv));
			dijkstra(i);
		}

		ans = lvl[n];

		if(ans == -1) cout << ans << endl;
		else{
			cur = n;
			while(1){
				ansV.push_back(cur);
				if(cur == 1) break;
				cur = priv[cur];
			}
			
			reverse(ansV.begin(), ansV.end());

			for(auto lol : ansV) cout << lol << " ";

			cout << endl;
		}
	}

	return 0;
}
