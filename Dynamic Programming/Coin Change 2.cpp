class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
            unordered_map<string,int>mp;
                    return solve(amount,coins,0,mp);
            
    }
    int solve(int amount,vector<int>&coins,int currentindex,unordered_map<string,int>&mp)
    {
            if(amount==0)
                    return 1;
            if(currentindex>=coins.size())
                    return 0;
           
            string key = to_string(currentindex)+'-'+to_string(amount);
            
            if(mp.find(key)!=mp.end())
                    return mp[key];
            int consider=0;
            
            if(coins[currentindex]<=amount)
                    consider=solve(amount-coins[currentindex],coins,currentindex,mp);
            
            int notconsider=solve(amount,coins,currentindex+1,mp);
            
            mp[key] = consider + notconsider;
            
            return consider+notconsider;
    }
};
