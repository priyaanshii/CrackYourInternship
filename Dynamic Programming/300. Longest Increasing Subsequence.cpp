class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
         return solve(nums,0,-1,nums.size(),dp);
    }
    int solve(vector<int>&nums,int ci,int prev,int n, vector<vector<int>>&dp)
    {
            if(ci>=n)
                    return 0;
            if(dp[ci][prev+1]!=-1)
                    return dp[ci][prev+1];
            
            int take=0;
            
            if(prev==-1 || nums[prev]<nums[ci])
                    take = 1 + solve(nums,ci+1,ci,n,dp);
            
            int donttake = solve(nums,ci+1,prev,n,dp);
            
            return dp[ci][prev+1]=max(take,donttake);
    }
};
