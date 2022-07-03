// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int ans=0;
    int release=0;
    int distinct=0;
    unordered_map<char,int>mp;
    
    for(int acquire=0;acquire<s.length();acquire++)
    {
        char cur_char = s[acquire];
        if(mp.find(cur_char)!=mp.end())
        {
            mp[cur_char]++;
        }
        else
        {
            mp[cur_char]=1;
            distinct++;
        }
        
        while(release<=acquire && distinct>k)
        {
            char dischar = s[release];
            release++;
            
            mp[dischar]--;
            if(mp[dischar]==0)
            {
                mp.erase(dischar);
                distinct--;
            }
        }
        
        if(distinct==k)
        {
            ans = max(ans,acquire-release+1);
        }
        
    }
    if(ans==0)
    return -1;
    else
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends
