class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
                mp[nums[i]]=1;
        }
            
        for(auto it : mp)
        {
                if(mp.find(it.first-1)!=mp.end())
                {
                        mp[it.first]=0;
                }
        }
            int len;
        for(int i=0;i<n;i++)
        {       
                if(mp[nums[i]]==1)
                {
                        len=1;
                        
                        while(mp.find(nums[i]+len)!=mp.end())
                        {
                                len++;
                        }
                }
                
                ans= max(ans,len);
        }
            
            return ans;
    }
};
