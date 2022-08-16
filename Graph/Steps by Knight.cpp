class Solution 
{
    public:
    bool isvalid(int xx,int xy,int n,vector<vector<bool>>&visited)
    {
        if(xx>=0 && xx<n && xy>=0 && xy<n && visited[xx][xy]==false)
        return true;
        else
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    int tx = TargetPos[0]-1;
	    int ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1;
	    int x2 = KnightPos[1]-1;
	    
	    if(x1==tx && x2==ty)
	    return 0;
	    
	    vector<vector<bool>>visited(n,vector<bool>(n,false));
	    queue<pair<int,int>>q;
	    q.push({x1,x2});
	    visited[x1][x2]=true;
	    
	    int ans=0;
	    
	    while(!q.empty())
	    {
	        int s = q.size();
	        ans++;
	        while(s!=0)
	        {
	            pair<int,int>p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	         
	         int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	         int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	         
	         for(int i=0;i<8;i++)
	         {
	             int nx = xx + ax[i];
	             int ny = yy + ay[i];
	             
	             if(nx==tx && ny==ty)
	             return ans;
	         
	             
	             if(isvalid(nx,ny,n,visited))
	             {
	                visited[nx][ny]=true;
	                q.push({nx,ny});
	             }
	             
	         }
	         s--;   
	        }
	    }
	    
	    return ans;
	}
};
