class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    vector<int>order;
	    vector<bool>visited(V,false);
	    queue<int>q;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(int n : adj[i])
	        {
	            indegree[n]++;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int c = q.front();
	        q.pop();
	        
	        if(visited[c]==true)
	        continue;
	        
	        visited[c]=true;
	        order.push_back(c);
	        
	        for(int n : adj[c])
	        {
	            indegree[n]--;
	            
	            if(indegree[n]==0)
	            q.push(n);
	        }
	    }
	    
	    return order;
	    
	}
};
