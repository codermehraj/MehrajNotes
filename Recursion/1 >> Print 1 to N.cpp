/*

    Printing 1 to n using recursion

*/

/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

void print_one_to_n(int n){
    if(n==1){
        // Base Case (if n=1 print 1)
        cout<<n<<endl;
        return ;
    }
    // Print 1 to n-1
    print_one_to_n(n-1);
    // After printing 1 to n-1 print n
    cout<<n<<endl;
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    // Using recursion to print from 1 to n
    print_one_to_n(n);
    return 0;
}
