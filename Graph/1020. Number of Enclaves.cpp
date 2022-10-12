class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
            
        for(int i=0;i<n;i++)
        {
               if(grid[0][i])
                       dfs(0,i,m,n,grid);
                
               if(grid[m-1][i])
                       dfs(m-1,i,m,n,grid);
               
        }
        
        int count=0;
        for(int j=0;j<m;j++)
        {
               if(grid[j][0])
                       dfs(j,0,m,n,grid);
              
               if(grid[j][n-1])
                       dfs(j,n-1,m,n,grid);
               
        }
            
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                       count+=grid[i][j];
                }
        }
        return count;
    }
    void dfs(int i,int j,int &m,int &n,vector<vector<int>>&grid)
    {
            if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
                    return ;
            
            
            grid[i][j]=0;
            cout<<"heloo";
            dfs(i+1,j,m,n,grid);
            dfs(i-1,j,m,n,grid);
            dfs(i,j+1,m,n,grid);
            dfs(i,j-1,m,n,grid);
    }
    
};
