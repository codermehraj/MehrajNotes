//Bismillahir Rahmanir Rahim
//codermehraj@gmail.com
#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
	int age , money ;
	bool married;
	Person() {age=0 , money=0 , married=0;};
	Person(int a, int b) { age=a , money=b ;};
	Person(int a, int b, bool c) {age =a , money=b, married=c; };
	void show(){
		cout<<"This Person has "<<money<<" taka in age "<<age<<endl;
		if(married) cout<<"He is married too :P\n";
		return ;
	}
	bool operator < (const Person& b) const {
		return age < b.age ;
	}
	bool operator > (const Person& b) const {
		return age > b.age ;
	}
};

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	Person a;
	set < Person , greater < Person > > P;
	for(int i=1;i<11;i++) {
		a.age=20-i;
		a.money=20*i;
		P.insert(a);
	}
	for(auto x: P) x.show();
	return 0;
}

//Alhamdulillah
