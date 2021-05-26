/*
	UVa 11906 - Knight in a War Grid

	In this problem you need to traverse the grid from (0,0)
	according to the conditions and count the number of possible moves from each one
	Then print the number of odd and even grids
*/
#include <bits/stdc++.h>

using namespace std;

bool waters[107][107], vis[107][107];

int dx[] = {1, -1,  1, -1};
int dy[] = {1,  1, -1, -1};
int evn, odd;

void inititate(){
	memset(waters, false, sizeof(waters));
	memset(vis, false, sizeof(vis));
	evn = odd = 0;
}

bool valid(pair < int , int >  tmp, int X, int Y){
	if(tmp.first >= 0 && tmp.first < X && tmp.second >= 0 && tmp.second < Y && !waters[tmp.first][tmp.second]) return true;
	return false;
}

void bfs(int x, int y, int X, int Y){
	queue < pair < int , int > > Q; 
	pair < int , int > tmp, nxt;
	set < pair < int , int > > st; // to calculate the even odds 
	Q.push({0,0});
	vis[0][0] = true;
	while(!Q.empty()){
		tmp = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			nxt.first = tmp.first + dx[i] * x;
			nxt.second = tmp.second + dy[i] * y;
			if(valid(nxt, X, Y)) st.insert(nxt);
			if(valid(nxt, X, Y) && !vis[nxt.first][nxt.second]){
				vis[nxt.first][nxt.second] = true;
				Q.push(nxt);
			}
		}
		for(int i=0;i<4;i++){
			nxt.first = tmp.first + dx[i] * y;
			nxt.second = tmp.second + dy[i] * x;
			if(valid(nxt, X, Y)) st.insert(nxt);
			if(valid(nxt, X, Y) && !vis[nxt.first][nxt.second]){
				vis[nxt.first][nxt.second] = true;
				Q.push(nxt);
			}
		}
	 	if(st.size()%2 == 0) evn++;
		else odd++;
		st.clear();
	}
}

int main(){

	/*
		R = number of horizontal grids
		C = number of vertical grid
		M = horizontal move
		N = vertical move
		W = number of watered cell
	*/
    int t, R, C, M, N, W, x, y, cs = 1;
    pair < int, int> p;
    cin >> t;
    while(t--){

    	inititate();

    	cin >> R >> C >> M >> N >> W;
    	
    	while(W--){
    		cin >> p.first >> p.second;
    		waters[p.first][p.second] = true;
    	}

    	bfs(M, N, R, C);

    	cout << "Case " << cs++ << ": " << evn << " " << odd << endl;

    }
    return 0;
}
