class Solution {
public:
    int maxProfit(vector<int>& prices) {
     vector<vector<int>>vec(prices.size(),vector<int>(2,-1));
     return solve(prices,0,1,1,vec);   
    }
    int solve(vector<int>& prices,int cur_i,int canbuy,int trans,vector<vector<int>>&vec)
    {
            if(cur_i>=prices.size())
                    return 0;
            if(vec[cur_i][canbuy]!=-1)
                    return vec[cur_i][canbuy];
            
            int idle = solve(prices,cur_i+1,canbuy,trans,vec);
            if(canbuy==1)
            {
                    int buy = -1*prices[cur_i]+solve(prices,cur_i+1,0,trans,vec);
                    vec[cur_i][canbuy] =  max(idle,buy);
            }
            else
            {
                    int sell = prices[cur_i] + solve(prices,cur_i+1,1,trans-1,vec);
                    vec[cur_i][canbuy] = max(idle,sell);
            }
            
            return vec[cur_i][canbuy];
    }
};
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int n=prices.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1])
                ans += prices[i] - prices[i - 1];
        }
        return ans;
    }
};*/
