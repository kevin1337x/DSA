// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(int arr[],int n,int idx,int prev,vector<int> &dp){
	    if(idx<0){
	        return 0;
	    }
	    
	   if(dp[prev]!=-1)
	        return dp[prev];
	   
	   int inc=0,exc=0;
	   
	   if(prev!=n and arr[idx]<arr[prev]){
	       inc = arr[idx] + solve(arr,n,idx-1,idx,dp);
	   }
	   else if(prev==n){
	       inc = arr[idx] + solve(arr,n,idx-1,idx,dp);
	   }
	   
	   exc = solve(arr,n,idx-1,prev,dp);
	   
	   dp[prev] = max(exc,inc);
	   return dp[prev];
	}
	
	int maxSumIS(int arr[], int n)
	{  
	   vector<int> dp(n+1,-1);
	   return solve(arr,n, n-1, n,dp);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends