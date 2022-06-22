class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
            int sum=10000;
            int n=matrix[0].size();
            vector<vector<int>>vec(102,vector<int>(102,-1));
            for(int i=0;i<n;i++)
            {
                    sum = min(sum,solve(matrix,0,i,n,vec));
            }
            return sum;
    }
    int solve(vector<vector<int>>& matrix,int cur_row,int cur_col,int n,vector<vector<int>>&vec)
    {
            if(cur_row>=n || cur_col>=n || cur_row<0 || cur_col<0)
                    return 10000;
            if(cur_row == n-1)
                    return matrix[cur_row][cur_col];

            if(vec[cur_row][cur_col]!=-1)
                    return vec[cur_row][cur_col];
            int d = matrix[cur_row][cur_col]+solve(matrix,cur_row+1,cur_col,n,vec);
            int dl = matrix[cur_row][cur_col]+solve(matrix,cur_row+1,cur_col-1,n,vec);
            int dr = matrix[cur_row][cur_col]+solve(matrix,cur_row+1,cur_col+1,n,vec);
            
            vec[cur_row][cur_col] = min(d,min(dl,dr));
            
            return vec[cur_row][cur_col];
    }
};
