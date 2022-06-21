class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        unordered_map<string,int>mp;
        return solve(grid.size(),grid[0].size(),0,0,mp,grid);
    }
int solve(int m,int n,int cur_row,int cur_col,unordered_map<string,int>&mp,vector<vector<int>>&grid)
    {
            if(cur_row==m-1 && cur_col==n-1)
                    return grid[cur_row][cur_col];
            if(cur_row>=m || cur_col>=n)
                    return 10001;
            int row = cur_row;
            int col = cur_col;
            string key = to_string(row) + '-' + to_string(col);
            if(mp.find(key)!=mp.end())
                    return mp[key];
            
            int right = grid[row][col]+solve(m,n,cur_row,cur_col+1,mp,grid);
            int down = grid[row][col]+solve(m,n,cur_row+1,cur_col,mp,grid);
            
            mp[key]=min(right,down);
            return mp[key];
    }
};
