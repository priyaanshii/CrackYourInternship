class Solution
{
    public:
    //Function to find the next greater element in left for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ans;
        stack<long long>st;
        
        for(long long i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                ans.push_back(-1);
            }
            else if(st.size()>0 && st.top()>arr[i])
            {
                ans.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=arr[i])
            {
                while(st.size()>0 && st.top()<=arr[i])
                {
                    st.pop();
                }
                
                if(st.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(st.top());
            }
            
            st.push(arr[i]);
        }
      
      return ans;
        
    }
};
