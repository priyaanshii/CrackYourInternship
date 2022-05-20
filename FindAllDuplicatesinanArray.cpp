/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int>s;
            vector<int>res;
            for(int i=0;i<nums.size();i++)
            {
                    if(s.find(nums[i])!=s.end())
                            res.push_back(nums[i]);
                    
                    else s.insert(nums[i]);
            }
            return res;
    }
};

//question link - https://leetcode.com/problems/find-all-duplicates-in-an-array/
