/*
	UVa 12442 – Forwarding Emails
	
	dfs through the nodes from 1
	use dp to store the depth along the way
	then continue to dp to the nodes which are not calculated using dp
	clear the visited array along the way

*/
#include <bits/stdc++.h>

using namespace std;

int n, u, v, cs = 1, ans, maxDepth;

int edges[50007];

bool vis[50007];
int depth[50007]; 

int dfs(int v) {
    int ago = 0;
    vis[v] = true;
	int nxt = edges[v];
    if (!vis[nxt]){
    	ago = dfs(nxt) + 1;
    }
    vis[v] = false;
    depth[v] = ago;
    return ago;
}

void dfsDriver(){
    memset(depth, 0, sizeof(depth));
    memset(vis, false, sizeof(vis));
    maxDepth = ans = 0;
    for(int i=1;i<=n;i++) {
        // optimize the number of dfs calls
        if (depth[i] == 0)
            dfs(i);
        if(depth[i] > maxDepth){
        	maxDepth = depth[i];
        	ans = i;
        }
    }
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--){
		
		cin >> n;
		
		for(int i=0;i<n;i++){
			cin >> u >> v;
			edges[u] = v;
		}

		dfsDriver();

		cout << "Case " << cs++ << ": ";
		cout << ans << endl;

	}

	return 0;
}
