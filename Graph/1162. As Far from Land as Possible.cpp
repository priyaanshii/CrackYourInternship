class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
       
        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<r;i++)
        {
          for(int j=0;j<c;j++)
          {
            if(grid[i][j]==1)
            {
              q.push({i,j});
              grid[i][j] = 2;
            }
          }
        }
          if(q.empty() || q.size()==r*c)
          {
            return -1;
          }

          int maxi=0;

          while(!q.empty())
          {
            int s=q.size();
            while(s--)
            {
              auto n=q.front();
              q.pop();
              for(int i=0;i<4;i++)
              {
                int next_i=n.first+dx[i];
                int next_j=n.second+dy[i];
                if(next_i>=0 && next_j>=0 && next_i<r && next_j<c)
                {
                  if(grid[next_i][next_j]==0)
                  {
                    q.push({next_i,next_j});
                    grid[next_i][next_j]=2;
                  }
                }
              }
            }
            maxi++;
          }
        return maxi-1;

    }
};
