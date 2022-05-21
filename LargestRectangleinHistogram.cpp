/*84. Largest Rectangle in Histogram
Hard

9960

145

Add to List

Share
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.*/
class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
       int max_area=-1;
           vector<int>nsl;
           vector<int>nsr;
           stack<pair<int,int>>s1;
           stack<pair<int,int>>s2;
           
           for(int i=0;i<heights.size();i++)
           {
                   if(s1.size()==0)
                           nsl.push_back(-1);
                   else if(s1.size()>0 && s1.top().first <heights[i])
                           nsl.push_back(s1.top().second);
                   else if(s1.size()>0 && s1.top().first>=heights[i])
                   {
                           while(s1.size()>0 &&s1.top().first>=heights[i])
                           
                                   s1.pop();
                                   
                                   if(s1.size()==0)
                                           nsl.push_back(-1);
                                   else 
                                           nsl.push_back(s1.top().second);
                           
                           
                   }
                   s1.push({heights[i],i});
           }
           for(int i=heights.size()-1;i>=0;i--)
           {
                   if(s2.size()==0)
                           nsr.push_back(heights.size());
                   else if(s2.size()>0 && s2.top().first<heights[i])
                           nsr.push_back(s2.top().second);
                   else if(s2.size()>0 && s2.top().first>=heights[i])
                   {
                           while(s2.size()>0 &&s2.top().first>=heights[i])
                           
                                   s2.pop();
                                   
                                   if(s2.size()==0)
                                           nsr.push_back(heights.size());
                                   else 
                                           nsr.push_back(s2.top().second);
                           
                           
                   }
                   s2.push({heights[i],i});
           }
           reverse(nsr.begin(),nsr.end());
           for(int i=0;i<heights.size();i++)
           {
                   max_area = max(heights[i]*(nsr[i]-nsl[i]-1),max_area);
           }
           return max_area;
           
    }
};
