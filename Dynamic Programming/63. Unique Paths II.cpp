class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string,int>mp;
        return solve(obstacleGrid.size(),obstacleGrid[0].size(),0,0,mp,obstacleGrid);
    }
int solve(int m,int n,int cur_row,int cur_col,unordered_map<string,int>&mp,vector<vector<int>>& obstacleGrid)
    {
            if(cur_row>=m || cur_col>=n || obstacleGrid[cur_row][cur_col]==1)
                    return 0;
            if(cur_row==m-1 && cur_col==n-1)
                    return 1;
            int row = cur_row;
            int col = cur_col;
            string key = to_string(row) + '-' + to_string(col);
            if(mp.find(key)!=mp.end())
                    return mp[key];
            
            int right = solve(m,n,cur_row,cur_col+1,mp,obstacleGrid);
            int down = solve(m,n,cur_row+1,cur_col,mp,obstacleGrid);
            
            mp[key]=right+down;
            return mp[key];
    }
};
