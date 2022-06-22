class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
            int m=matrix.size();
            int n=matrix[0].size();
            unordered_map<string,int>mp;
            int side;
            for(int i=0;i<m;i++)
            {
                    for(int j=0;j<n;j++)
                    {
                            if(matrix[i][j]=='1')
                                    side = max(side,solve(i,j,m,n,matrix,mp));                
                    }
            }
            return side*side;
    }
int solve(int cur_row,int cur_col,int m,int n,vector<vector<char>>& matrix,unordered_map<string,int>&mp)
{
        if(cur_row>=m || cur_row<0 || cur_col>=n || cur_col<0 || matrix[cur_row][cur_col]=='0')
                return 0;
        string key = to_string(cur_row) + '-' + to_string(cur_col);
        if(mp.find(key)!=mp.end())
                return mp[key];
        
        int right = 1+solve(cur_row,cur_col+1,m,n,matrix,mp);
        int down = 1+solve(cur_row+1,cur_col,m,n,matrix,mp);
        int diagright = 1+solve(cur_row+1,cur_col+1,m,n,matrix,mp);
        return mp[key]=min(right,min(down,diagright));
}
};
