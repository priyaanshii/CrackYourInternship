class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool>rec_stack(v,false);
        vector<bool>visited(v,false);
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i] && hascycle(v,adj,i,rec_stack,visited))
            return true;
        }
        
        return false;
    }
    
    bool hascycle(int v,vector<int>adj[],int cur_v,vector<bool>&rec_stack,vector<bool>&visited)
    {
        visited[cur_v]=true;
        rec_stack[cur_v]=true;
        
        for(auto cur_neigh : adj[cur_v])
        {
            if(!visited[cur_neigh] && hascycle(v,adj,cur_neigh,rec_stack,visited))
            return true;            
            else if(rec_stack[cur_neigh]==true)
            return true;
        }
        rec_stack[cur_v]=false;
        
        return false;
        
    }
};
