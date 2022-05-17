/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     vector<int> vec;
        int count_zeros=0;                  
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                count_zeros++;        
            else
                vec.push_back(nums[i]);  
        }
        while(count_zeros)      
        {
            vec.push_back(0);
            count_zeros--;
        }
        for(int i=0;i<nums.size();i++)     
        {
            nums[i]=vec[i];
        }
        
    }
};
