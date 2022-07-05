class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans=0;
        vector<vector<vector<int>>>dp(102,vector<vector<int>>(102,vector<int>(602,-1)));
        ans = solve(strs,m,n,0,dp);
        return ans;
    }
    int solve(vector<string>& strs,int m,int n,int cur_i,vector<vector<vector<int>>>&dp)
    {
            if(cur_i==strs.size() || m<0 || n<0)
                    return 0;
            
            //string key = to_string(m)+'-'+to_string(n)+'-'+to_string(cur_i);
            
            if(dp[m][n][cur_i]!=-1)
                    return dp[m][n][cur_i];
            
            int countzeros = count(strs[cur_i].begin(),strs[cur_i].end(),'0');
            int countones = count(strs[cur_i].begin(),strs[cur_i].end(),'1');
            int consider=0;
            if(m-countzeros>=0 && n-countones>=0)
            consider = 1 + solve(strs,m-countzeros,n-countones,cur_i+1,dp);
            int notconsider = solve(strs,m,n,cur_i+1,dp);
            
            dp[m][n][cur_i]=max(consider,notconsider);
            
            return dp[m][n][cur_i];
    }
};
