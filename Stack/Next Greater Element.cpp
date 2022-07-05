/* ---BRUT FORCE APPROACH---(will give tle)*/
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ans;
        int next=-1;
        for(int i=0;i<n;i++)
        {
            next=-1;
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]<arr[j])
                {
                    next=arr[j];
                    ans.push_back(next);
                    break;
                }
            }
            if(next==-1)
            ans.push_back(-1);
        }
        return ans;
        
    }
};

/* ---using STACK--- (all test cases passed) */

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long>ans;
        stack<long long>st;
        
        for(long long i=n-1;i>=0;i--)
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
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
