/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';

void print_n_to_one(int n){
    if(n==1){
        // Base Case (if n=1 print 1)
        cout<<n<<endl;
        return ;
    }
    // before printing (x < n) print n then print n-1 to 1
    cout<<n<<endl;
    // Print n-1 to 1
    print_n_to_one(n-1);
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    // Using recursion to print from n to 1
    print_n_to_one(n);
    return 0;
}
