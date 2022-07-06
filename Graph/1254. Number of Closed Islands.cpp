class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
            int m=grid.size();
            int n=grid[0].size();
            
            for(int cur_col=0;cur_col<n;cur_col++)
            {
                    if(grid[0][cur_col]==0)
                            dfs(grid,0,cur_col,m,n);
                    if(grid[m-1][cur_col]==0)
                            dfs(grid,m-1,cur_col,m,n);
            }
            for(int cur_row=0;cur_row<m;cur_row++)
            {
                    if(grid[cur_row][0]==0)
                            dfs(grid,cur_row,0,m,n);
                    if(grid[cur_row][n-1]==0)
                            dfs(grid,cur_row,n-1,m,n);
            }
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(grid[i][j]==0)
                            {
                                    dfs(grid,i,j,m,n);
                                    ans++;
                            }
                    }
            }
            return ans;
    }
    void dfs(vector<vector<int>>& grid,int cur_row,int cur_col,int m,int n)
    {
            if(cur_row<0 || cur_row>=m || cur_col<0 || cur_col>=n || grid[cur_row][cur_col]==1)
                    return;
            
            grid[cur_row][cur_col]=1;
            
            dfs(grid,cur_row-1,cur_col,m,n);
            dfs(grid,cur_row+1,cur_col,m,n);
            dfs(grid,cur_row,cur_col-1,m,n);
            dfs(grid,cur_row,cur_col+1,m,n);

    return;
          }
};
