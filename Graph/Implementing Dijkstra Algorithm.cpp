class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>costt(V,INT_MAX);
        vector<bool>visited(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,S});
        costt[S]=0;
        
        while(!q.empty())
        {
            auto currentpair = q.top();
            int cost = currentpair.first;
            int ver = currentpair.second;
            q.pop();
            
            if(visited[ver])
            continue;
            
            visited[ver] = true;
            costt[ver] = cost;
            
            for(int i=0;i<adj[ver].size();i++)
            {
                int neighnode = adj[ver][i][0];
                int curcost = adj[ver][i][1];
                if(visited[neighnode])
                continue;
            
                q.push({cost + curcost , neighnode});
            }
        }
        
        return costt;
    }
};
