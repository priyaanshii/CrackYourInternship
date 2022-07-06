class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
            int n=board[0].size();
            
            for(int cur_row=0;cur_row<m;cur_row++)
            {
                    for(int cur_col=0;cur_col<n;cur_col++)
                    {
                            if(board[cur_row][cur_col]==word[0] && dfs(board,cur_row,cur_col,0,word,m,n))
                                    return true;
                    }
            }
            return false;
    }
    bool dfs(vector<vector<char>>& board,int cur_row,int cur_col,int cur_i,string word,int m,int n)
    {
            if(cur_i>=word.size())
                    return true;
            
            if(cur_row<0 || cur_row>=m || cur_col<0 || cur_col>=n || board[cur_row][cur_col]!=word[cur_i])
                    return false;
            
            char temp=board[cur_row][cur_col];
            board[cur_row][cur_col]='.';
            
            bool found = dfs(board,cur_row+1,cur_col,cur_i+1,word,m,n) || dfs(board,cur_row-1,cur_col,cur_i+1,word,m,n) ||dfs(board,cur_row,cur_col-1,cur_i+1,word,m,n) || dfs(board,cur_row,cur_col+1,cur_i+1,word,m,n);
            
            board[cur_row][cur_col]=temp;
            
            return found;
    }
};
