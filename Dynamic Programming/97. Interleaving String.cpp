class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
            
            unordered_map<string,bool>mp;
        return solve(s1,s2,s3,0,0,0,mp);
    }
    bool solve(string s1, string s2, string s3,int i,int j,int k,unordered_map<string,bool>&mp)
    {
            if(i==s1.length() && j==s2.length() && k==s3.length())
                    return true;
            
            string key = to_string(i) + '-' + to_string(j) + '-' + to_string(k);
             if(mp.find(key)!=mp.end())
                     return mp[key];
            bool x=false,y=false;
            
            if(i<s1.length() && s1[i]==s3[k])
                    x= solve(s1,s2,s3,i+1,j,k+1,mp);
            if(j<s2.length() && s2[j]==s3[k])
                    y= solve(s1,s2,s3,i,j+1,k+1,mp);
            mp[key]=x||y;
                    return mp[key];
    }
};
