/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

/*
    Sum of 1 to n is = 1+2+3+... ...+ n
    so, sum_1_to_n(n) = sum_1_to_n(n-1) + n
    which meanse our recursion will be :
    sum(n) = sum(n-1) + n
*/

int get_one_to_n_sum(int n){
    // As sum of 1 to 1 is 1
    if(n==1) return 1;
    // Otherwise sum(n) = sum(n-1) + n
    else return get_one_to_n_sum(n-1)+n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    // Using recursion to get sum from 1 to n
    cout<<get_one_to_n_sum(n)<<endl;
    return 0;
}

