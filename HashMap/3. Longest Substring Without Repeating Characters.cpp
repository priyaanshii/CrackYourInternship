class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
            int ans=0;
            int i=0;
            for(int j=0;j<s.size();j++)
            {
                    char cur_char = s[j];
                    
                    while(i<j && mp.find(s[j])!=mp.end())
                    {
                            mp.erase(s[i]);
                            i++;
                    }
                    mp[s[j]]=j;
                    ans = max(ans,j-i+1);
            }
            
            return ans;
    }
};
