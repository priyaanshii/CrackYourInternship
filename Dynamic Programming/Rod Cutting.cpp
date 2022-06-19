// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>vec(1002,vector<int>(1002,-1));
        return solve(price,n,0,vec);
    }
    int solve(int price[],int l,int cur_i,vector<vector<int>>&vec)
    {
        if(l==0)
        return 0;
        
        if(cur_i >= l)
        return 0;
        if(vec[cur_i][l]!=-1)
        return vec[cur_i][l];
        int cur_length = cur_i+1;
        int consider=0;
        if(cur_length <= l)
        {
            consider = price[cur_i] + solve(price,l-cur_length,cur_i,vec);
        }
        
        int notconsider = solve(price,l,cur_i+1,vec);
        
        vec[cur_i][l] = max(consider,notconsider);
        
        return max(consider,notconsider);
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
