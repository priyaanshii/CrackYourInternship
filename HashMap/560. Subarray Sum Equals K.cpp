class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int prefixSum=0;
        unordered_map<int,int>mp;
        mp[prefixSum]=1;
            
            for(int curval : nums)
            {
                    prefixSum+=curval;
                    
                    if(mp.find(prefixSum-k)!=mp.end())
                    {
                            ans+=mp[prefixSum-k];
                    }
                    if(mp.find(prefixSum)!=mp.end())
                    {
                            mp[prefixSum]++;
                    }
                    else
                            mp[prefixSum]=1;
            }
            
            return ans;
    }
};
