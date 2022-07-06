class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        if(grid[sr][sc]==color)
                return grid;
            
            dfs(grid,sr,sc,grid[sr][sc],color);
            
            return grid;
    }
    void dfs(vector<vector<int>>& grid,int cr,int cc,int c,int color)
    {
            if(cr<0 || cr>=grid.size() || cc<0 || cc>=grid[0].size() || grid[cr][cc]!=c)
                   return;
            grid[cr][cc]=color;
            
            dfs(grid,cr-1,cc,c,color);
            dfs(grid,cr+1,cc,c,color);
            dfs(grid,cr,cc-1,c,color);
            dfs(grid,cr,cc+1,c,color);
             return;
    }
};
