class Solution {
public:
    #define MOD 1000000007
    int numRollsToTarget(int n, int k, int target) {
        unordered_map<string,int>mp;
        return solve(n,k,target,mp);
    } 
    int solve(int n,int f,int targetSum,unordered_map<string,int>&mp)
    {
            if(targetSum==0 && n==0)
                    return 1;
            if(targetSum!=0 && n==0)
                    return 0;
            
            string key = to_string(n) + '-' + to_string(targetSum);
            if(mp.find(key)!=mp.end())
                    return mp[key];
            int ans=0;
            for(int i=1;i<=f;i++)
            {
                    int tempans = solve(n-1,f,targetSum-i,mp);
                    ans = (ans%MOD+tempans%MOD)%MOD;
            }
            
            mp[key]=ans;
            return ans;
    }
};
