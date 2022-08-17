class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int,int>>maxh;
            for(int i=0;i<points.size();i++)
            {
                    maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1] , i });
                    if(maxh.size()>k)
                    {
                            maxh.pop();
                    }
            }
            vector<vector<int>>ans;
            while(maxh.size()>0)
            {
                    int i = maxh.top().second;
                    ans.push_back({points[i][0] , points[i][1]});
                    maxh.pop();
            }
            
            return ans;
    }
};
