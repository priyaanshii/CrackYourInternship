class Solution{
    public:
    int lenOfLongSubarr(int nums[],int N, int k) 
    { 
        // Complete the function
        int ans=0;
        int prefixSum=0;
        unordered_map<int,int>mp;
        mp[prefixSum]=-1;
            
            for(int i=0;i<N;i++)
            {
                    prefixSum+=nums[i];
                    
                    if(mp.find(prefixSum-k)!=mp.end())
                    {
                            ans = max(ans,i-mp[prefixSum-k]);
                    }
                    if(mp.find(prefixSum)==mp.end())
                    {
                            mp[prefixSum]=i;
                    }
            }
            
            return ans;
    } 

};
