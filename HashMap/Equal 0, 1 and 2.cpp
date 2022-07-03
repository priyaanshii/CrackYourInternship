// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string s) {
        // code here
        int z0=0,z1=0,z2=0;
        int ans=0;
        unordered_map<string,int>mp;
        string exp = to_string(z1-z0) + '-' + to_string(z2-z1);
        mp[exp]=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            z0++;
            else if(s[i]=='1')
            z1++;
            else
            z2++;
            exp = to_string(z1-z0) + '-' + to_string(z2-z1);
            if(mp.find(exp)!=mp.end())
            {
                ans=ans+mp[exp];
                mp[exp]++;
            }
            else
            {
                mp[exp]=1;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends
