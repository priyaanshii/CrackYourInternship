class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
            unordered_map<int,int>mp;
            
            for(int i=0;i<arr.size();i++)
            {
                    int cur_remainder = ((arr[i]%k)+k)%k;
                    if(mp.find(cur_remainder)!=mp.end())
                          mp[cur_remainder]+=1;
                    else
                          mp[cur_remainder]=1;
            }
            
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                    if(it->first==0)
                    {
                            if(mp[it->first]%2!=0)
                                    return false;
                    }
                    else if(mp.find(k-it->first)==mp.end())
                                    return false;
                    else if (mp[it->first]!=mp[k-it->first])
                                    return false;
            }
            
            return true;
    }
};
