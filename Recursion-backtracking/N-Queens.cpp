class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));    
        vector<vector<string>>ans;
        solve(grid,ans,0,n);
        return ans;
    }

    void solve(vector<vector<char>>&grid,vector<vector<string>>&ans,int currentrow,int n)
    {
      if(currentrow==n)
      {
        ans.push_back(flatten(n,grid));
        return;
      }

      for(int i=0;i<n;i++)
      {
        if(isvalid(grid,currentrow,i,n))
        {
          grid[currentrow][i]='Q';
          solve(grid,ans,currentrow+1,n);
          grid[currentrow][i]='.';
        }
      }
    }

    bool isvalid(vector<vector<char>>&grid,int i,int j,int &n)
    {
      //Row check
        for(int k=0;k<n;k++)
        {
            if(grid[i][k]=='Q')
                return false;
        }
        
        //column check
        for(int k=0;k<n;k++)
        {
            if(grid[k][j]=='Q')
                return false;
        }
        
        //upper left diag check
        
        for(int k=1;k<=n;k++)
        {
            if(i-k<0 or j-k<0)
                break;
            
            if(grid[i-k][j-k]=='Q')
                return false;
        }
        
        //Upper right diag
        for(int k=1;k<=n;k++)
        {
            if(i-k<0 or j+k>=n)
                break;
            
            if(grid[i-k][j+k]=='Q')
                return false;
        }
        
        //lower left diag
        for(int k=1;k<=n;k++)
        {
            if(i+k>=n or j-k<0)
                break;
            
            if(grid[i+k][j-k]=='Q')
                return false;
        }
        
        //lower right diag
        
        for(int k=1;k<=n;k++)
        {
            if(i+k>=n or j+k>=n)
                break;
            
            if(grid[i+k][j+k]=='Q')
                return false;
        }
        
        return true;
    }

    vector<string>flatten(int&n,vector<vector<char>>&grid)
    {
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            string curr="";
            for(int j=0;j<n;j++)
                curr+=grid[i][j];
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};
