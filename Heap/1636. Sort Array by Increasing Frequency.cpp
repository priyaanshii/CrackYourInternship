class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto n : nums)
                mp[n]++;
        priority_queue<pair<int,int>>heap;
        for(auto m : mp)
        {
                heap.push({-1 * m.second,m.first});
        }
        vector<int>ans;
        while(heap.size()>0)
        {
                int s = -1 * heap.top().first;
                for(int i=0;i<s;i++)
                        ans.push_back(heap.top().second);
                heap.pop();
        }
        return ans;
    }
};
