class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int n = s.size();
        vector<string>valid;
        helper(s,ans,0,n-1,valid);
        return ans;
    }
    void helper(string s,vector<vector<string>>&ans,int start,int end,vector<string>valid)
    {
      if(start>end)
      {
        ans.push_back(valid);
        return ;
      }

      for(int i=start;i<=end;i++)
      {
        string leftpart = s.substr(start,i+1-start);
        if(pallindrome(leftpart))
        {
          valid.push_back(leftpart);
          helper(s,ans,i+1,end,valid);
          valid.pop_back();
        }
      }
    }
    bool pallindrome(string s)
    {
      for(int i = 0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                return false;
            }
        }
        return true;
    }
};
