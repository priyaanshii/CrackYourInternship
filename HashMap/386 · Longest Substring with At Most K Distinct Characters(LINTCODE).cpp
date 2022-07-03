class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
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
            ans = max(ans,acquire-release+1);
        
        
    }
    return ans;

    }
};
