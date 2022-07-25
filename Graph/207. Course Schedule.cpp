class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>>graph = constructgraph(numCourses,prerequisites);
            
            vector<int>indegree(numCourses);
            
            for(int curcourse=0;curcourse<numCourses;curcourse++)
            {
                    for(int curneigh : graph[curcourse])
                    {
                            indegree[curneigh]++;
                    }
            }
            
            queue<int>q;
            
            for(int i=0;i<numCourses;i++)
            {
                    if(indegree[i]==0)
                    {
                            q.push(i);
                    }
            }
            
            vector<bool>visited(numCourses,false);
            vector<int>order;
            
            while(!q.empty())
            {
                    int curCour = q.front();
                    q.pop();
                    
                    if(visited[curCour]==true)
                            continue;
                    visited[curCour]=true;
                    order.push_back(curCour);
                    for(int neigh : graph[curCour])
                    {
                            indegree[neigh]--;
                            if(indegree[neigh]==0)
                                    q.push(neigh);
                    }
            }
            
            if(order.size()!=numCourses)
                    return false;
            return true;
    }
    vector<vector<int>> constructgraph(int n, vector<vector<int>>&edges)  
     {
         vector<vector<int>>g(n);
        for(auto it:edges)
        {
            int v = it[0];
            int u = it[1];
            g[u].push_back(v);
        }
        return g;
     }
   
};
