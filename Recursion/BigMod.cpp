#include<bits/stdc++.h>
using namespace std;

long int bigmod(long int a,long int b,long int m){
	if(b==0) {
		//cout<<1%m<<endl;
		return 1%m;
	}
	long int x=bigmod(a,b/2,m);
	x=(x*x)%m;
	if(b%2==1) x=(x*(a%m))%m;
	//cout<<"("<<a<<","<<b<<","<<m<<") = "<<x<<endl;
	return x;
}

int main(){
	long int a,b,m;
	while(cin>>a>>b>>m) cout<<bigmod(a,b,m)<<endl;
	return 0;
}
