class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>hp;
            
            for(int i=0;i<matrix.size();i++)
            {
                    for(int j=0;j<matrix[0].size();j++)
                    {
                            hp.push(matrix[i][j]);
                            if(hp.size()>k)
                                    hp.pop();
                    }
                    
            }
            return hp.top();
    }
};
