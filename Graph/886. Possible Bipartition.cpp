class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
            vector<vector<int>>graph = constructgraph(n,dislikes);

            vector<int>color(n+1,-1);
            
            for(int currentvertex=0;currentvertex<=n;currentvertex++)
            {
                    if(currentvertex==0 || color[currentvertex]!=-1)
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
    vector<vector<int>> constructgraph(int n,vector<vector<int>>&edges)
    {
            vector<vector<int>>graph(n+1);
            for(auto edge : edges)
            {
                    int a = edge[0];
                    int b = edge[1];
                    
                    graph[a].push_back(b);
                    graph[b].push_back(a);
            }
            
            return graph;
    }
};
