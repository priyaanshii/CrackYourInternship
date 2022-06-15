class Solution {
public:
    int rob(vector<int>& nums) {
            unordered_map<int,int>mp;
        return robcost(0,nums,mp);
    }
    int robcost(int cur,vector<int>&nums,unordered_map<int,int>&mp)
    {
            if(cur>=nums.size())
                    return 0;
            
            int c=cur;
            if(mp.find(c)!=mp.end())
                    return mp[c];
            
            int one = nums[cur] +robcost(cur+2,nums,mp);
            int two = robcost(cur+1,nums,mp);
            
            mp[c]=max(one,two);
            
            return mp[c];
    }
};
