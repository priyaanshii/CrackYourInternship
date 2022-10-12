class Solution {
public:
   	void dfs(int i,int j,vector<vector<char>>& board){

		if(i>=board.size() || j>=board[0].size() || i<0 || j<0)
			return;

		if(board[i][j]!='O')
			return;

		board[i][j]='#';

		dfs(i-1,j,board);
		dfs(i,j-1,board);
		dfs(i,j+1,board);
		dfs(i+1,j,board);
	}
	void solve(vector<vector<char>>& board) {

		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].size();j++){
				if(i==0 || j==0 || i==board.size()-1 || j==board[i].size()-1){
					if(board[i][j]=='O')
						dfs(i,j,board);
				}
			}
		}

		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].size();j++){
				if(board[i][j]=='O')
					board[i][j]='X';
				if(board[i][j]=='#')
					board[i][j]='O';
			}
		}

	}
};
