// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int ans=0;
	    int ps=0;
	    unordered_map<int,int>mp;
	    mp[0]=-1;
	    
	    for(int i=0;i<n;i++)
	    {
	        ps+=arr[i];
	        int currem = ((ps%k)+k)%k;
	        if(mp.find(currem)!=mp.end())
	        {
	            ans=max(ans,i-mp[currem]);
	        }
	        if(mp.find(currem)==mp.end())
	        {
	            mp[currem]=i;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends
