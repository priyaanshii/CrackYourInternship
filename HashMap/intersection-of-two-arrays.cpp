class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,bool>mp;
            
        for(auto i : nums1)
        {
                if(mp.find(i)==mp.end())
                {
                        mp[i] = true;
                }
        }
            
        for(auto j : nums2)
        {
                if(mp.find(j)!=mp.end() && mp[j]==true)
                {
                        ans.push_back(j);
                        mp.erase(j);
                }
        }
            
            return ans;
    }
};
