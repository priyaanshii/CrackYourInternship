/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            unordered_map<int,int>mp;
            for(int i=0;i<nums.size();i++)
            {
                    mp[nums[i]]++;
            }
            for(auto j=mp.begin();j!=mp.end();j++)
            {
                    if(j->second != 1)
                            return j->first;
            }
            
           return 0;
    }
};
