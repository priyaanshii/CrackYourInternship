class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>vec(s.length()+1,vector<int>(s.length()+1,-1));
            string w=s;
            reverse(s.begin(),s.end());
            return solve(s,w,0,0,s.length(),s.length(),vec);
    }
    int solve(string &s1,string &s2,int i,int j,int m,int n,vector<vector<int>>&vec)
    {
            if(i>=m || j>=n)
                    return 0;
            int ans=0;
            
            if(vec[i][j]!=-1)
                    return vec[i][j];
            
            if(s1[i]==s2[j])
            {
                   ans = 1 + solve(s1,s2,i+1,j+1,m,n,vec);
            }
            else
            {
                    int b = solve(s1,s2,i+1,j,m,n,vec);
                    int c = solve(s1,s2,i,j+1,m,n,vec);
                    
                    ans = max(b,c);
            }
            vec[i][j] = ans;
            return ans;
            
    }
};
