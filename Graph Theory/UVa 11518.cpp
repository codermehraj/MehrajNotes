/*
    UVa 11518: Dominos 2
    
    Connent all the reletions of the falling domins 
    dfs from the source(manually forced dominos)
    
*/

#include <bits/stdc++.h>

using namespace std;

// mp will store which domino will cause fall to which(s) dominos
unordered_map < int , vector < int > > mp;

// to mark the visited dominos in dfs
unordered_map < int , bool > isFallen;

int number_of_dominos_falled;

void initiateData(){	
	number_of_dominos_falled = 0; // initially no domino was falled
	// clearing the test case data
	mp.clear(); 
	isFallen.clear(); 	
}

void fall_other_dominos_from(int x){
	
	// base case: the domino is fallen already
	if(isFallen[x]) return;
	isFallen[x] = true;
	number_of_dominos_falled++;

	for(auto childDominos: mp[x]){
		if(!isFallen[childDominos]) fall_other_dominos_from(childDominos);
	}

}

int main(){
	
	ios_base::sync_with_stdio(0); cin.tie(0);
    
	/*
		n = number of dominos
		m = number of domino connections
		l = number of  times manually domino pushed
	*/

    int t, n, m, l, x, y;
    cin >> t;

    while(t--){
    	
    	cin >> n >> m >> l;

    	initiateData(); // initiating all

    	while(m--){
    		
    		// x will cause fall of y
    		cin >> x >> y;
    		mp[x].push_back(y);
    		isFallen[x] = isFallen[y] = false;

    	}
   	
    	while(l--){

    		// x domino is forced to fall manually
    		cin >> x;
    		fall_other_dominos_from(x); // dfs to fall other dependent dominos

    	}

    	cout << number_of_dominos_falled << endl;

    }

    return 0;
}
