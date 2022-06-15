class Solution {
public:
    int tribonacci(int n) {
            unordered_map<int,int>mp;
        return find(n,mp);
    }
    int find(int n,unordered_map<int,int>&mp)
    {
            if(n==0)
                    return 0;
            if(n==1)
                    return 1;
            if(n==2)
                    return 1;
            
            int p = n;
            if(mp.find(p)!=mp.end())
                        return mp[p];
            
            int a = find(n-1,mp);
            int b = find(n-2,mp);
            int c = find(n-3,mp);
            
            mp[p]=a+b+c;
            
            return mp[p];
    }
};
