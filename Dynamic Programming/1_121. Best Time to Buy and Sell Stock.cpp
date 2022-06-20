class Solution {
public:
    int maxProfit(vector<int>& prices) {
     vector<vector<vector<int>>>vec(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
     return solve(prices,0,1,1,vec);   
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
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
            unordered_map<int,int>mp;
            return find(prices,mp,0);
    }
    int find(vector<int>& prices,unordered_map<int,int>&mp,int cur)
    {
            if(cur>=prices.size())
                    return 0;
            int yes = prices[cur] + find(prices,mp,cur+1);
            int no = find(prices,mp,cur);
            
            return max(yes,no);
    }
};*/
