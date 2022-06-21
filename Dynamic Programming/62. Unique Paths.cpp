class Solution {
public:
    int uniquePaths(int m, int n) {
            unordered_map<string,int>mp;
        return solve(m,n,0,0,mp);
    } 
    int solve(int m,int n,int cur_row,int cur_col,unordered_map<string,int>&mp)
    {
            if(cur_row==m-1 && cur_col==n-1)
                    return 1;
            if(cur_row>=m || cur_col>=n)
                    return 0;
            int row = cur_row;
            int col = cur_col;
            string key = to_string(row) + '-' + to_string(col);
            if(mp.find(key)!=mp.end())
                    return mp[key];
            
            int right = solve(m,n,cur_row,cur_col+1,mp);
            int down = solve(m,n,cur_row+1,cur_col,mp);
            
            mp[key]=right+down;
            return mp[key];
    }
};
