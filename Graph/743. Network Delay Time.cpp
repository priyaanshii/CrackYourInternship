class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>>graph = constructGraph(times,n);
        return min_time(graph,n,k);
    }
    vector<vector<vector<int>>> constructGraph(vector<vector<int>>&edges,int n)
    {
            vector<vector<vector<int>>>graph(n+1);
            
            for(int i=0;i<=n;i++)
            {
                    graph.push_back({{}});
            }
            
            for(vector<int>edge : edges)
            {
                    int src = edge[0];
                    int dest = edge[1];
                    int time = edge[2];
                    
                    graph[src].push_back({dest,time});
            }
            
            return graph;
    }
    int min_time(vector<vector<vector<int>>>&graph,int n,int src)
    {
            vector<int>time(n+1,0);
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
            vector<bool>visited(n+1,false);
            time[src]=0;
            q.push({0,src}); //{cost , node }
            
            while(!q.empty())
            {
                    auto cp = q.top();
                    q.pop();
                    
                    int tme = cp.first;
                    int nod = cp.second;
                    
                    if(visited[nod]==true)
                            continue;
                    
                    visited[nod] = true;
                    time[nod] = tme;
                    
                    for(int i=0;i<graph[nod].size();i++)
                    {
                            int neigh_node = graph[nod][i][0];
                            int neigh_time = graph[nod][i][1];
                            
                            if(visited[neigh_node]==true)
                                    continue;
                            
                            q.push({neigh_time + tme , neigh_node});
                    }
            }
            
            for(int i=1;i<=n;7
                i++)
            if(visited[i]==0)
                    return -1;
            int ans=0;
            for(auto x : time)
            {
                    ans = max(ans,x);
            }
            return ans;
    }
    
};
