class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(grid[i][j]=='1')
                            {
                                    dfs(grid,i,j,m,n);
                                    ans++;
                            }
                    }
            }
            
            return ans;
    }
    void dfs(vector<vector<char>>& grid,int cur_row,int cur_col,int m,int n)
    {
            if( cur_row<0 || cur_col<0 || cur_row>=m || cur_col>=n || grid[cur_row][cur_col]=='0')
                    return;
            
            grid[cur_row][cur_col]='0';
            
            dfs(grid,cur_row-1,cur_col,m,n);
            dfs(grid,cur_row+1,cur_col,m,n);
            dfs(grid,cur_row,cur_col-1,m,n);
            dfs(grid,cur_row,cur_col+1,m,n);
            return;            
    }
};
