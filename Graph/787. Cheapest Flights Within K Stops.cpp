class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<int>temp(n,INT_MAX);
            vector<int>costs(n,INT_MAX);
            
            temp[src]=0;
            costs[src]=0;
            
            for(int i=0;i<=k;i++)
            {
                    for(auto edge : flights)
                    {
                            int source = edge[0];
                            int dest = edge[1];
                            int cost = edge[2];
                            
                            if(temp[source]!=INT_MAX)
                                    costs[dest] = min(costs[dest], temp[source]+cost);
                    }
                    
                    temp = costs;
            }
            
            if(costs[dst]==INT_MAX) return -1 ;
                    else 
                    return costs[dst] ;
    }
};
