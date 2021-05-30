/*
	UVa 558 - Wormholes

	USE BELMEN FORD ~ DETECT NEG CYCLE
	
*/
#include <bits/stdc++.h>

using namespace std;

struct edge{
	int u, v, cost;	
};

edge tmp;

vector < edge > edges;
int n, m, u, v, x;

int dis[1007];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	/*
		n = number of universe
		m = number of wormholes
	*/

	int t;
	string ans;
	cin >> t;

	while(t--){

		ans = "not possible";
		cin >> n >> m;
		
		for(int i=0;i<m;i++){
			cin >> tmp.u >> tmp.v >> tmp.cost;
			edges.push_back(tmp);
		}

		memset(dis, 99999999, sizeof(dis));
		dis[0] = 0;

		for(int j=1;j<=n;j++){
			for(int i=0;i<m;i++){
				if(dis[edges[i].u] + edges[i].cost < dis[edges[i].v]){
					dis[edges[i].v] = dis[edges[i].u] + edges[i].cost;
					if(j==n) ans = "possible";
				}
			}
		}

		cout << ans << endl;

		edges.clear();
	}

	return 0;
}
