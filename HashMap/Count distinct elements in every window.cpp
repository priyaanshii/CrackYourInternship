// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int,int>mp;
        int distinct=0;
        for(int i=0;i<k;i++)
        {
            if(mp.find(A[i])!=mp.end())
            {
                mp[A[i]]++;
            }
            else
            {
                mp[A[i]]=1;
                distinct++;
            }
        }
        ans.push_back(distinct);
        int release=0;
        for(int acquire=k;acquire<n;acquire++)
        {
            mp[A[release]]--;
            if(mp[A[release]]==0)
            {
                mp.erase(A[release]);
                distinct--;
            } 
            release++;
             if(mp.find(A[acquire])!=mp.end())
            {
                mp[A[acquire]]++;
            }
            else
            {
                mp[A[acquire]]=1;
                distinct++;
            }
            
            ans.push_back(distinct);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
