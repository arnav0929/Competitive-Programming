// Sliding Window 1. Max Sum Sub Array
#include<bits/stdc++.h>
using namespace std;


#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define lli long long int

/*
k = subarray size
x = max of sum of subarray should be less than x
n = size of array ar[]
complexity = O(n)
*/

void maxSubarraySum(int ar[], int n, int k, int x)
{
    int sum = 0,ans=0;
    for(int i=0; i<k; i++)
        sum += ar[i];

    if(sum<x)    
        ans = sum;
    for(int i=k; i<n; i++)
    {
        sum = sum+ar[i]-ar[i-k];
        if(sum<x) //if(sum<x && ans<sum)
            ans = max(sum, ans);
    }
    cout<<ans<<" is Max Sub-array Sum\n";
}

int main()
{
    int n,x,k;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
    cin>>k>>x;
    maxSubarraySum(ar, n,k,x);

    return 0;
}


/*
6
7 5 4 6 8 9
3 20
18 is Max Sub-array Sum
*/