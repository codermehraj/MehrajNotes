/*
	UVa 11504: dominos

	Connent all the reletions of the falling domins 
    topologically sort and calcualte the optimal order of forcing dominos to fall
	after topological sort visit as the sorted order and calcualte the number of components in the graph

*/

#include <bits/stdc++.h>

using namespace std;

// mp will store which domino will cause fall to which(s) dominos
unordered_map < int , vector < int > > mp;

// to mark the visited dominos in dfs
unordered_map < int , bool > isFallen;

// to store the topoligally sorted order
vector < int > visit_order;

// to mark visited in the topological sort
vector< int> vis;

int number_of_root_dominos;

void initiateData(){	
	number_of_root_dominos = 0; // initially no domino was falled as root
	// clearing the test case data
	mp.clear(); 
	isFallen.clear(); 	
	visit_order.clear();
}

// visiting from x node using dfs
void visit(int x){
	vis[x] = true;
	for(auto child: mp[x]){
		if(!vis[child]) visit(child);
	}
	visit_order.push_back(x);
}

// function to run the topological sort
void topoligally_sort(int n){
	vis.assign(n+1,false);
	for(int i=1;i<=n;i++){
		if(!vis[i]) visit(i);
	}
	reverse(visit_order.begin(), visit_order.end());
}

void fall_other_dominos_from(int x){
	
	// base case: the domino is fallen already
	if(isFallen[x]) return;
	isFallen[x] = true;
	
	for(auto childDominos: mp[x]){
		if(!isFallen[childDominos]) fall_other_dominos_from(childDominos);
	}

}

int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	/*
		n = number of dominos
		m = number of domino connections
	*/

    int t, n, m, x, y;
    cin >> t;

    while(t--){
    	
    	cin >> n >> m;

    	initiateData(); // initiating all

    	while(m--){
    		
    		// x will cause fall of y
    		cin >> x >> y;
    		mp[x].push_back(y);
    		isFallen[x] = isFallen[y] = false;

    	}

    	topoligally_sort(n);
   	
    	for(auto possibleRootDominos: visit_order){
    		if(!isFallen[possibleRootDominos]) {
    			fall_other_dominos_from(possibleRootDominos);
    			number_of_root_dominos++;
    		}
    		//cout << possibleRootDominos << " " << number_of_root_dominos << endl;
    	}

    	cout << number_of_root_dominos << endl;

    }

    return 0;
}
