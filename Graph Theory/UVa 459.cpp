/*
	UVa 459: Graph Connectivity

	Here just visit randomly
	number of source / root from which dfs will run is the ans
	Here it is basically the number of components in the graph

*/

#include <bits/stdc++.h>

using namespace std;

// to store the graph
unordered_map < char , vector < char > > mp;

// to mark the visited nodes
unordered_map < char, bool > vis;

int number_of_visit;

// initiating for each test case
void initiate(){
	number_of_visit = 0;
	mp.clear();
	vis.clear();
}

// using dfs to teverse the graph
void visit(char x){
	vis[x] = true;
	for(auto child: mp[x]){
		if(!vis[child]) visit(child);
	}
}

int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	int t;
	char n; // value of maximum node
	string s;

	cin >> t;

	while(t--){
		
		initiate();

		cin >> n;
		getline(cin, s);

		while(1){
			getline(cin, s);
			if(s.size() == 0) break;
			mp[s[0]].push_back(s[1]);
			mp[s[1]].push_back(s[0]);
		}

		for(char i = 'A'; i <= n ; i++) vis[i] = false;
		
		for(char i = 'A'; i <= n ; i++){
			if(!vis[i]) {
				visit(i);
				number_of_visit++; // number of components++
			}
		}

		cout << number_of_visit << endl;

		if(t) cout << endl;
	}

    return 0;
}
