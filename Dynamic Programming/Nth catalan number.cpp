// { Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        vector<cpp_int>vec(1001,-1);
        return solve(n,vec);
    }
    cpp_int solve(int n,vector<cpp_int>&vec)
    {
        if(n==0 || n==1)
        return 1;
        
        int cur=n;
        
        if(vec[cur]!=-1)
        return vec[cur];
        
        cpp_int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans = ans + solve(i,vec)*solve(n-i-1,vec);
        }
        
        vec[cur]=ans;
        return vec[cur];
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends
