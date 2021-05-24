#include <bits/stdc++.h>
using namespace std;

int r,c,ans;
char jhamela[150][150];

void jhamela_sesh( int i, int j){
	jhamela[i][j]='*';
	if(i-1>=0 && j-1>=0 && jhamela[i-1][j-1]=='@')
		jhamela_sesh(i-1,j-1);
	if(i-1>=0  && jhamela[i-1][j]=='@')
		jhamela_sesh(i-1,j);
	if(i-1>=0 && j+1<c && jhamela[i-1][j+1]=='@')
		jhamela_sesh(i-1,j+1);

	if( j-1>=0 && jhamela[i][j-1]=='@')
		jhamela_sesh(i,j-1);
	if( j+1<c && jhamela[i][j+1]=='@')
		jhamela_sesh(i,j+1);

	if(i+1<r && j-1>=0 && jhamela[i+1][j-1]=='@')
		jhamela_sesh(i+1,j-1);
	if(i+1<r  && jhamela[i+1][j]=='@')
		jhamela_sesh(i+1,j);
	if(i+1<r && j+1<c && jhamela[i+1][j+1]=='@')
		jhamela_sesh(i+1,j+1);
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>r>>c){
		if(r==0 && c==0) break;
		ans=0;
		//char jhamela[r+1][c+1];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>jhamela[i][j];
				//cout<<jhamela[i][j];
			}
			//jhamela[i][c]='\0';
			//cout<<endl;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(jhamela[i][j]=='@'){
					ans++;
					jhamela_sesh(i,j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
