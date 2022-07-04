class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V,false);
        solve(adj,V,0,visited,ans);
        return ans;
    }
    void solve(vector<int> adj[],int v,int curvertex,vector<bool>&visited,vector<int>&ans)
    {
        if(visited[curvertex]==true)
        return;
        
        visited[curvertex]=true;
        ans.push_back(curvertex);
        
        vector<int>neigh = adj[curvertex];
        
        for(auto it : neigh)
        {
            solve(adj,v,it,visited,ans);
        }
        
        return ;
    }
    
};
