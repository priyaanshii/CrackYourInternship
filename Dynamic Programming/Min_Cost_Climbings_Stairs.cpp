class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
            unordered_map<int,int>mp;
        return min(findcost(cost,0,mp),findcost(cost,1,mp));
    }
        int findcost (vector<int>cost,int current_index,unordered_map<int,int>&mp)
        {
                if(cost.size()==current_index)
                        return 0;
                if(cost.size()<current_index)
                        return 1001;
                int key = current_index;
                if(mp.find(key)!=mp.end())
                        return mp[key];
                int onejump = cost[current_index] + findcost(cost,current_index+1,mp);
                int twojump = cost[current_index] + findcost(cost,current_index+2,mp);

                mp[key] = min(onejump,twojump);
                
                return min(onejump,twojump);
        }
};
