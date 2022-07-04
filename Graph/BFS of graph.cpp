class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<int>ans;
        vector<int>visited(V,false);
        
        q.push(0);
        
        while(!q.empty())
        {
            int curver = q.front();
            q.pop();
            
            if(visited[curver])
            continue;
            
            visited[curver]=true;
            ans.push_back(curver);
            for(int neigh : adj[curver])
            q.push(neigh);
        }
        
        return ans;
    }
};
