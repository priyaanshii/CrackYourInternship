class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot=0;
            for(int i=0;i<nums.size();i++)
                    tot+=nums[i];
            
            if(tot%2!=0)
                    return false;
            unordered_map<string,int>mp;
            return solve(nums,0,tot/2,mp);
    }
        bool solve(vector<int>&nums,int cur,int target,unordered_map<string,int>&mp)
        {
                if(target==0)
                        return true;
                
                if(cur>=nums.size())
                        return false;
                
                string key = to_string(cur) + '-' + to_string(target);
                if(mp.find(key)!=mp.end())
                        return mp[key];
                
                bool consider=false;
                
                if(nums[cur]<=target)
                consider = solve(nums,cur+1,target-nums[cur],mp);
                
                if(consider)
                        return true;
                
                bool notconsider = solve(nums,cur+1,target,mp);
                
                mp[key] = consider||notconsider;
                
                return mp[key];
        }
};
