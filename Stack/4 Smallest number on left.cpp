
class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
         vector<int>ans;
        stack<int>s;
        
        for(int i=0;i<n;i++)
        {
            if(s.size()==0)
            {
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top()<arr[i])
            {
                ans.push_back(s.top());
            }
            else if(s.size()>0 && s.top()>=arr[i])
            {
                while(s.size()>0 && s.top()>=arr[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                ans.push_back(-1);
                else
                ans.push_back(s.top());
            }
            s.push(arr[i]);
            
        }
        return ans;
    }
};
