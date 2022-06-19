class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
            int ans = solve(coins,amount,0,dp);
            if(ans==100001)
                    return -1;
            else 
                    return ans;
    }
        int solve(vector<int>& coins, int amount,int cur_index,vector<vector<int>>&dp)
        {
                if(amount==0)
                        return 0;
                
                if(cur_index == coins.size())
                        return 100001;
                
                if(dp[cur_index][amount]!=-1) 
                        return dp[cur_index][amount];
                int consider=100001;
                
                if(coins[cur_index] <= amount)
                        consider = 1 + solve(coins,amount-coins[cur_index],cur_index,dp);
                
                int notconsider = solve(coins,amount,cur_index+1,dp);
                
                dp[cur_index][amount] = min(consider,notconsider);
                
                return dp[cur_index][amount];
        }
};
