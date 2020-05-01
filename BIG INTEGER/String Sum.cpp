#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

string sum(string a, string b){
	int lim=max(a.size(),b.size());
	int ans,dig1,dig2,carry=0;
	string summ,ANS;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i = 0 ; i < lim ; i++)
	{
		ans=carry;
		if(a.size()>i) ans+=(int)a[i]-(int)'0';
		if(b.size()>i) ans+=(int)b[i]-(int)'0';
		if(ans>9){
			carry=ans/10;
			ans=ans%10;
		}
		else carry=0;
		summ+=(char)(ans+(int)'0');
	}
	if(carry>0) summ+=(char)(carry+(int)'0');
	reverse(summ.begin(),summ.end());
	int flag=1;
	for(int i=0;i<summ.size();i++){
        if(summ[i]!='0' && flag==1) flag=0;
        if(flag==0) ANS+=summ[i];
	}
	if(ANS.size()==0) ANS="0";
	return ANS;
}
int main()
{
	string a,b;
	while(cin>>a>>b){
        cout<<sum(a,b)<<endl;
	}
	return 0;
}
