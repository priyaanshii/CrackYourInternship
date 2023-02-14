class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum=0,targetsum=0,unvis=nums.size(),max_val=-1,n=nums.size();

        for(int i=0;i<n;i++)
        {
          totalsum+=nums[i];
          max_val=max(max_val,nums[i]);
        }

        targetsum=totalsum/k;

        if(totalsum%k || max_val>targetsum || n<k)
        return false;

        vector<bool>visited(n,false);

        return solve(0,0,unvis,targetsum,visited,nums,k,n);
    }
    bool solve(int ci,int cs,int &unvis,int &targetsum, vector<bool>&visited,vector<int>&nums,int k,int n)
    {
       if(k==1)
       return true;

       if(cs==targetsum)
       return solve(0,0,unvis,targetsum,visited,nums,k-1,n);

       if(unvis==0 || ci>=n)
       {
         return false;
       }

       for(int j=ci;j<n;j++)
       {
         if(visited[j]==false && cs+nums[j]<=targetsum)
         {
           visited[j]=true;
           unvis--;

           if(solve(j+1,cs+nums[j],unvis,targetsum,visited,nums,k,n))
           return true;

           visited[j]=false;
           unvis++;
         }
       }
       return false;
    }
};
