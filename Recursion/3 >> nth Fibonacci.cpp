/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

// Fibonnaci Siries :: 1 1 2 3 5 8 13 21 34 ...
// so, nth fib is (n-1)th fib + (n-2)th fib

int get_nth_fib(int n){
    // As first two elements are 1
    if(n<3) return 1;
    // Otherwise fib(n) = fib(n-1) + fib(n-2)
    else return get_nth_fib(n-1)+get_nth_fib(n-2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    // Using recursion to get nth fibonacci number
    cout<<get_nth_fib(n)<<endl;
    return 0;
}
