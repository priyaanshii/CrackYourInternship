class Solution {
public:
    int numSquares(int n) {
        vector<int>vec(n+1,-1);
        return solve(n,vec);
    }
    int solve(int n,vector<int>&vec)
    {
            if(n==0)
                    return 0;
            if(n<0) return 1e8;
            //string key = to_string(n);
            
            if(vec[n]!=-1)
                    return vec[n];
            
            int ans=INT_MAX;
            
            for(int i = 1 ; i*i<=n ;i++)
            {
                    int temp = i*i;
                    int a = 1+solve(n-temp,vec);
                    ans = min(ans,a);
            }
            
            vec[n] = ans;
            return ans;
     }
};
