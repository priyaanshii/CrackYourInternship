class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
            unordered_map<string,int>mp;
        return solve(nums,target,0,mp);
    }
    int solve(vector<int>& nums, int target,int cur,unordered_map<string,int>&mp)
    {
            if(target==0 && cur==nums.size())
                    return 1;
            if(target!=0 && cur==nums.size())
                    return 0;
            
            string key = to_string(cur)+'-'+to_string(target);
            
            if(mp.find(key)!=mp.end())
                    return mp[key];
            int possign = solve(nums,target-nums[cur],cur+1,mp);
            int negsign = solve(nums,target+nums[cur],cur+1,mp);
            
            mp[key]= possign + negsign;
            return mp[key];
    }
};
