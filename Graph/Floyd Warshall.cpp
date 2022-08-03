
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int m = matrix.size();
	    
	    vector<vector<int>>dist(m,vector<int>(m));
	    
	    for(int i=0;i<m;i++)
	        for(int j=0;j<m;j++)
	            dist[i][j]=matrix[i][j];
	    
	    for(int intermed=0;intermed<m;intermed++)
	    {
	        for(int source=0;source<m;source++)
	        {
	            for(int dest=0;dest<m;dest++)
	            {
	                if(dist[source][intermed]!=-1 && dist[intermed][dest]!=-1)
	                {
	                    if(dist[source][dest]==-1)
	                    {
	                        dist[source][dest] = dist[source][intermed] + dist[intermed][dest];
	                    }
	                    else
	                    dist[source][dest] = min(dist[source][dest],dist[source][intermed] + dist[intermed][dest]);
	                }
	            }
	        }
	    }
	     for(int i=0;i<m;i++)
	        for(int j=0;j<m;j++)
	            matrix[i][j]=dist[i][j];
	    
	    
	    
	}
};
