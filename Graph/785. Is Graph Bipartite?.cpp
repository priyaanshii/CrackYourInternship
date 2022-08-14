class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int>color(n,-1);
            
            for(int currentvertex=0;currentvertex<n;currentvertex++)
            {
                    if(color[currentvertex]!=-1)
                            continue;
                    
                    if(!hasevencycle(currentvertex,n,graph,0,color))
                            return false;
                        
            }
            
            return true;
    }
    bool hasevencycle(int cv , int n, vector<vector<int>>&graph,int cc,vector<int>&color)
    {
            if(color[cv]!=-1)
                    return color[cv]==cc;
            
            color[cv]=cc;
            for(int curneigh : graph[cv])
            {
                    if(!hasevencycle(curneigh,n,graph,1-cc,color))
                            return false;
                            
            }
            return true;
    }
};
