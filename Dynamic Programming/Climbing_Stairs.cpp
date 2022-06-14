class Solution {
public:
    int climbStairs(int n) {
            unordered_map<int,int>mp;
       int t = totalways(0,n,mp);
            return t;
    }
        int totalways(int cs ,int n,unordered_map<int,int>&mp)
        {
                if(cs==n)
                        return 1;
                if(cs>n)
                        return 0;
                
                int c=cs;
                
                if(mp.find(c)!=mp.end())
                        return mp[cs];
                
                int onejump = totalways(cs+1,n,mp);
                int twojump = totalways(cs+2,n,mp);

                mp[c] = onejump+twojump;
                
                return mp[c];
        }
};
