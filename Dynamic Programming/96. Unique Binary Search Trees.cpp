class Solution {
public:
    int numTrees(int n) {
        vector<int>vec(n+1,-1);
            return solve(n,vec);
    }
        int solve(int n,vector<int>&vec)
        {
                if(n==0||n==1)
                        return 1;
                if(vec[n]!=-1)
                        return vec[n];
                int ans=0;
                for(int i=0;i<n;i++)
                {
                        ans+=solve(i,vec)*solve(n-i-1,vec);
                }
                return vec[n]=ans;
        }
};
