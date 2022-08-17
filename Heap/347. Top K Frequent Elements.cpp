class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
            unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++)
            {
                    mp[nums[i]]++;
            }
            for(auto m : mp)
            {
                    heap.push({m.second,m.first});
                    if(heap.size()>k)
                            heap.pop();
            }
            vector<int>ans;
            while(heap.size()>0)
            {
                    ans.push_back(heap.top().second);
                    heap.pop();
            }
            return ans;
    }
};
