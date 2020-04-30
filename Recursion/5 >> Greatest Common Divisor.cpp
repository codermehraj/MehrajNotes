/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    We are using old school Euclidian Algorithm to get gcd
    According to that if we want to get gcd(a,b)
    What we do is: 
        while b!=0
            We just make b = a%b
            and also :
            we make a = b ~ < SWAP(a,b) >
        if b becomes ZERO we find a as the ans...

    So, in recursion :
        our base case will be gcd(a,0)=a
        otherwise : gcd(a,b) = gcd(b,a%b)
*/

int get_gcd(int a, int b){
    // As gcd(a,0)=a
    if(b==0) return a;
    // Otherwise gcd(a,b) = gcd(b,a%b)
    return get_gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    // Using recursion to get gcd of a and b
    cout<<get_gcd(a,b)<<endl;
    return 0;
}
