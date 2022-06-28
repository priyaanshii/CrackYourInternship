class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
            
            unordered_map<int,int>mp;
            vector<int>ans;
            for(int i=0 ; i<nums.size(); i++){
           for(int j=0; j<nums[i].size(); j++)
                    {
                            mp[nums[i][j]]++;
                    }
            }
            
            for(auto it : mp)
            {
                    if(it.second==nums.size())
                    {
                            ans.push_back(it.first);
                    }
            }
            sort(ans.begin(),ans.end());
            
            return ans;
    }
   /* vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
    }    */
};
