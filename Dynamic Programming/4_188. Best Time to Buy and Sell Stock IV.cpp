class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>vec(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
     return solve(prices,0,1,k,vec); 
    }
   int solve(vector<int>& prices,int cur_i,int canbuy,int trans,vector<vector<vector<int>>>&vec)
    {
            if(cur_i>=prices.size() || trans==0)
                    return 0;
            if(vec[cur_i][canbuy][trans]!=-1)
                    return vec[cur_i][canbuy][trans];
            
            int idle = solve(prices,cur_i+1,canbuy,trans,vec);
            if(canbuy==1)
            {
                    int buy = -1*prices[cur_i]+solve(prices,cur_i+1,0,trans,vec);
                    vec[cur_i][canbuy][trans] =  max(idle,buy);
            }
            else
            {
                    int sell = prices[cur_i] + solve(prices,cur_i+1,1,trans-1,vec);
                    vec[cur_i][canbuy][trans] = max(idle,sell);
            }
            
            return vec[cur_i][canbuy][trans];
    }
};
