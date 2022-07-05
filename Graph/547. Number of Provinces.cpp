class Solution {
public:
    int findCircleNum(vector<vector<int>>& graph) {
        int ans=0;
        int n=graph.size();
        vector<bool>visited(n);
        
            for(int curcity=0;curcity<n;curcity++)
            {
                  if(visited[curcity]==false)
                  {
                          dfs(visited,graph,n,curcity);
                          ans++;
                  }
            }
            
            return ans;
    }
    void dfs(vector<bool>&visited,vector<vector<int>>& graph,int n,int curcity)
    {
            if(visited[curcity])
                    return;
            
            visited[curcity]=true;
            
            vector<int>neigh = graph[curcity];
            
            for(int i=0;i<n;i++)
            {
                    if(neigh[i]==1)
                            dfs(visited,graph,n,i);
            }
            
            return;
    }
    /*
void dfs(vector<bool>&visited,vector<vector<int>>& graph,int n,int curcity)
    {
            if(visited[curcity])
                    return;
            
            visited[curcity]=true;
            
            vector<int>neigh = graph[curcity];
            
            for(int i=0;i<n;i++)
            {
                    if(neigh[i]==1)
                            dfs(visited,graph,n,i);
            }
            
            return;
    }
*/
};
