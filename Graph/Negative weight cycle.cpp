class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>costs(n,INT_MAX);
	    costs[0]=0;
	    
	    for(int i=0;i<n-1;i++)
	    {
	        for(auto edge : edges)
	        {
	            int src = edge[0];
	            int dest = edge[1];
	            int wt = edge[2];
	            
	            if(costs[src]!=INT_MAX)
	            {
	                costs[dest] = min(costs[dest],wt + costs[src]);
	            }
	        }
	    }
	    for(auto edge : edges)
	        {
	            int src = edge[0];
	            int dest = edge[1];
	            int wt = edge[2];
	            
	            if(costs[src]!=INT_MAX && costs[dest] > costs[src] + wt)
	            {
	               return 1;
	            }
	        }
	    
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
