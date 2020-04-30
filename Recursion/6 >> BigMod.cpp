/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    We are using Bigmod Algorithm to get (a^b)%m
    According to that if we want to get(a^b)%m
    What we do is: 
    We divide the problem in 2 parts
        Then calculate one part and the other is the same
    if b is even >> (a^b)%m = ((a^(b/2))*(a^(b/2)))%m
    if b is odd >> (a^b)%m = (a*(a^(b/2))*(a^(b/2)))%m
    
    So, in recursion :
        our base case will be bigmod(a,0,m)=1%m
        otherwise : 
            < b is even > bigmod(a,b,m) = bigmod(a,b/2,m)^2;
            < b is odd > bigmod(a,b,m) = bigmod(a,b/2,m)^2*a;
*/

long int bigmod(long int a,long int b,long int m){
    if(b==0) {
        // as a^0 = 1
        // 1%m cz m could be less than 2
        return 1%m;
    }
    // if b is even >> (a^b)%m = ((a^(b/2))*(a^(b/2)))%m
    long int x=bigmod(a,b/2,m);
    // we didn't mod x cz returned values are already moded
    x=(x*x)%m;
    if(b%2==1) x=(x*(a%m))%m; // For odd multiply an extra 1
    // if b is odd >> (a^b)%m = (a*(a^(b/2))*(a^(b/2)))%m
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long int a,b,m;
    cin>>a>>b>>m;
    // Using recursion to get (a^b)%m with Bigmod
    // This is one kind of divide and conqure approach
    cout<<bigmod(a,b,m)<<endl;
    return 0;
}
