class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        
        for(int cur_vertex=0;cur_vertex<v;cur_vertex++)
        {
            if(visited[cur_vertex]==false)
            {
                if(hascycle(adj,cur_vertex,-1,visited))
                return true;
            }
        }
        
        return false;
    }
    
    bool hascycle(vector<int>adj[],int cur_v,int cur_p,vector<bool>&visited)
    {
        visited[cur_v]=true;
        
        for(auto neigh : adj[cur_v])
        {
            if(visited[neigh]==false)
            {
                if(hascycle(adj,neigh,cur_v,visited))
                return true;
            }
            else if(neigh != cur_p)
            return true;
        }
        
        return false;
    }
};
