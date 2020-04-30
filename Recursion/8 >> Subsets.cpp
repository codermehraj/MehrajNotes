/* ~ CoderMehraJ ~ */
#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << #x << " = " << x << '\n';
/*
    So to get all the subset of a string s
    we need all the binary representation from 0 to 2^(|s|)-1
    Where |s| = length of s
    e.g: if s="abc" ~ |s|=3
    The subsets will be :: (0 means we will not take it and 1 means gonna take it)
        000     >>>     ""
        001     >>>     "c"
        010     >>>     "b"
        011     >>>     "bc"
        100     >>>     "a"
        101     >>>     "ac"
        110     >>>     "ab"
        111     >>>     "abc"
    
    So Here we will use recursion to genarate the binary sequence for a given |s|
    Here we can see that we take an element once and then next time we dont take that
    So each element is toogled in each step
    So, The recurance will be:
            Start from the i=0th index
            make ith index 0 and then get subset form i to |s|
            Then :
            make ith index 1 and then get subset form i to |s|
            now when will we stop?
            You see the base case will be when i is equal to |s|
            In the base case we will print the "0101010..." string
    That was quite Hard :P
    Releted problem : UVa 10776
*/

string counter;
// counter will be used to make "101010..." string 
int sze; 
// the value of |s|
vector < string > ans;
// list of the subsets

void subset(int i){
    if(i==sze) {
        // Base case
        // Push this combination to the ans list
        ans.push_back(counter);
        return ;
    }
    counter[i]='0';
    // Not taking i and genarating i+1 to |s| subset
    subset(i+1);
    // Taking i and genarating i+1 to |s| subset
    counter[i]='1';
    subset(i+1);
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
        cin>>sze;
        counter="";
        // Initiating "0101010..." string by zeros
        for(int i=0;i<sze;i++) counter+="0";
        subset(0);
        for(auto x: ans){
            // Printing the list
            cout<<x<<endl;
        }
        
    return 0;
}
//fixed<<setprecision(1)
