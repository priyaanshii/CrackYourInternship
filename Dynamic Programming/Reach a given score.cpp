// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function
int solve(long long int n,int cur_index,vector<int>&nums)
{
    if(n==0)
    return 1;
    
    if(n<0 || cur_index >=3)
    return 0;
    
    int consider;
    consider = solve(n-nums[cur_index],cur_index,nums);
    
    int notconsider = solve(n,cur_index+1,nums);
    
    return consider+notconsider;
}

long long int count(long long int n)
{
	vector<int>nums;
	//vector<vector<int>vec(4,vector<int>(n++1,-1));
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(10);
	return solve(n,0,nums);
}
// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends
