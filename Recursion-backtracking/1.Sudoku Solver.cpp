problem link- https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        solve(board,0,0,n);
        return ;
    }
    bool solve(vector<vector<char>>& board,int cr,int cc,int n)
    {
      // the case where we have solved the problem
      if(cr==n)
      return true;
      
      //making nr and nc variable as new row and new column for cases like :
      //special case : if current row is 0, current column is 8 then next row should be 1 and next column should be 0. 
      //so if current col is less then 8 then simply increment current column and row will remain same.
      int nr;
      int nc;
      if(cc!=n-1)
      {
        nr=cr;
        nc=cc+1;
      }
      else
      {
        nr=cr+1;
        nc=0;
      }

      //if particular block is already solved, then solve the next block
      if(board[cr][cc]!='.')
      return solve(board,nr,nc,n);
        
        //for an empty block we can fill 1-9 numbers, before we have to check wheather the number is valid or not.
        //if valid, then put the value and find the number for the next block
        //if problem solved that means if recursive function returns true, then return true. you don't need to explore the values.
        //everytime backtrack and try other possibilties(if problem not solved).
        for(int currentval=1;currentval<=9;currentval++)
        {
          if(isvalid(board,cr,cc,n,currentval+'0'))
          {
            board[cr][cc]=currentval+'0';
            if(solve(board,nr,nc,n))
            {
                return true;
            }
            board[cr][cc]='.';
          }
        }
      //return false, if not able to solve the problem.
      return false;
    }

    bool isvalid(vector<vector<char>>& board,int cr,int cc,int n,char cv)
    {
      //three conditions to the particular character is valid or not.
      //1.Each of the digits 1-9 must occur exactly once in each row.
      //2.Each of the digits 1-9 must occur exactly once in each column.
      //3.Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
      return isrowvalid(board,cr,cc,n,cv) && iscolvalid(board,cr,cc,n,cv) && issubgridvalid(board,cr,cc,n,cv);
    }

    bool isrowvalid(vector<vector<char>>& board,int cr,int cc,int n,char cv)
    {
      for(int i=0;i<n;i++)
      {
        if(board[cr][i]==cv)
        return false;
      }
      return true;
    }
    bool iscolvalid(vector<vector<char>>& board,int cr,int cc,int n,char cv)
    {
      for(int i=0;i<n;i++)
      {
        if(board[i][cc]==cv)
        return false;
      }
      return true;
    }
    bool issubgridvalid(vector<vector<char>>& board,int cr,int cc,int n,char cv)
    {
      int startrowindex=3*(cr/3);
      int startcolindex=3*(cc/3);

      for(int i=startrowindex;i<=startrowindex+2;i++)
      {
        for(int j=startcolindex;j<=startcolindex+2;j++)
        {
          if(board[i][j]==cv)
          return false;
        }
      }

      return true;
    }
};
