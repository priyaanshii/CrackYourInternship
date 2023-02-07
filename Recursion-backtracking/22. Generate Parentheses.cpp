class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,"",n,ans);
        return ans;
    }
    void solve(int opencount,int closecount,string expr,int n,vector<string>&ans)
    {
      if(opencount==closecount && opencount==n)
      {
        ans.push_back(expr);
        return;
      }

      if(opencount<n)
      {
        solve(opencount+1,closecount,expr+"(",n,ans);
      }

      if(opencount>closecount)
      {
        solve(opencount,closecount+1,expr+")",n,ans);
      }
      return;
    }
};
