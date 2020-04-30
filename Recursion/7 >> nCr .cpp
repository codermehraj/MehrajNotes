/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    We are using a combinatorics formula to calculate nCr
    The formula is :
        nCr = (n-1)C(r-1) + (n-1)C(r)
        So, The recursive formula will be: 
        nCr(n,r) = nCr(n-1,r-1) + nCr(n-1,r)
        Lets find out :D
        Releted Problem : UVa 369
        Maybe time is hard !!!
*/
int nCr(int n, int r){
    // As nCn = 1
    if(n==r) return 1;
    // As nC1 = n
    if(r==1) return n;
    return nCr(n-1,r-1)+nCr(n-1,r); 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,r;
    cin>>n>>r;
    // Using recursion to get nCr
    cout<<nCr(n,r)<<endl;
    return 0;
}
