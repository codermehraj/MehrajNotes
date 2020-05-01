#include<bits/stdc++.h>
#define MAX 1002
using namespace std;

string leading_zero(string a){
	int flag=1;
	string ANS;
	for(int i=0;i<a.size();i++){
        if(a[i]!='0' && flag==1) flag=0;
        if(flag==0) ANS+=a[i];
	}
	if(ANS.size()==0) ANS="0";
	return ANS;
}

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


string multi(string a, char ch){
	int b=(int)ch-'0';
	int carry=0,bit,hi;
	string ans;
	reverse(a.begin(),a.end());
	for(int i=0; i<a.size(); i++){
		bit=(int)a[i]-(int)'0';
		hi=(bit*b)+carry;
		bit=hi%10;
		carry=hi/10;
		ans+=(char)(bit+(int)'0');
	}
	if(carry!=0) ans+=(char)(carry+(int)'0');
	reverse(ans.begin(),ans.end());
	return ans;
}

string multiply(string a, string b){
	string x,y,ans="0",temp;
	a=leading_zero(a);
	b=leading_zero(b);
	if(a.size()>b.size()) {
		x=a; y=b;
	}
	else {
		x=b; y=a;
	}
	reverse(y.begin(),y.end());
	for(int i=0;i<y.size();i++){
		temp=multi(x,y[i]);
		for(int j=1;j<=i;j++) temp+="0";
		ans=sum(ans,temp);
	}
	return ans;
}

string tostring(int a){
	string ans;
	while(a>0){
		ans+=(char)((a%10)+(int)'0');
		a=a/10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int n;
	string s;
	vector < string > ans(MAX+1);
	ans[1]="1";
	for(int i=2;i<=MAX;i++){
		s=tostring(i);
		ans[i]=multiply(s,ans[i-1]);
	}
	while(cin>>n){
		printf("%d!\n",n);
		if(n<2){
			printf("1");
		}
		else for(int i=0;i<ans[n].size();i++){
			printf("%c",ans[n][i]);
		}
		printf("\n");
	}
	return 0;
}

