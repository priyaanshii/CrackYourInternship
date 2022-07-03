class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,ps=0;
        unordered_map<int,int>mp;
            mp[0]=1;
            for(int curval : nums)
            {
                    ps+=curval;
                    
                    int currem = ((ps%k)+k)%k;
                    
                    if(mp.find(currem)!=mp.end())
                    {
                            ans+=mp[currem];
                            mp[currem]++;
                    }
                    else
                    {
                            mp[currem]=1;
                    }
            }
            
            return ans;
    }
};
