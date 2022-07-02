class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<string,int>mp;
            return solve(0,0,triangle.size(),triangle,mp);
    }
    int solve(int cur_row,int cur_col,int m,vector<vector<int>>& triangle,unordered_map<string,int>&mp)
    {
            if(cur_row == m-1)
                    return triangle[cur_row][cur_col];
            
            if(cur_row>=m || cur_col>=triangle[cur_row].size())
                    return 10001;
            
            string key = to_string(cur_row) + "-" + to_string(cur_col);
            
            if(mp.find(key)!=mp.end())
                    return mp[key];
            
            int move1 = triangle[cur_row][cur_col] + solve(cur_row+1,cur_col,m,triangle,mp);
            int move2 = triangle[cur_row][cur_col] + solve(cur_row+1,cur_col+1,m,triangle,mp);
            
            mp[key] = min(move1,move2);
            
            return mp[key];
    }
};
