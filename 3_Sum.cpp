class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
            if(nums.size() < 3) return {};
            vector<vector<int>> res;
            sort(nums.begin(),nums.end());
            for(int i=0;i<=nums.size()-3;i++)
            {
                    if(i>0 && nums[i]==nums[i-1]) continue;
                    int sum=nums[i];
                    int j=i+1;
                    int k=nums.size()-1;
                    int t = 0-nums[i];
                    while(j<k)
                    {
                           
                            sum=nums[j]+nums[k];
                            if(sum > t)
                               k--;
                            else if(sum<t)
                                    j++;
                            else
                            { 
                                    res.push_back(vector<int>{nums[i],nums[j],nums[k]});
                                    j++;
                                    k--;
                                    while(k>j && nums[k]==nums[k+1]) k--;
                                    while(k>j && nums[j]==nums[j-1]) j++;
                            }
                            
                    }
            }
            
            return res;
    }
};
