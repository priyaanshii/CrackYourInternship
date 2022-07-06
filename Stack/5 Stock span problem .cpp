    vector <int> calculateSpan(int arr[], int n)
    {
       vector<int>ngl;
       stack<pair<int,int>>st;
       for(int i=0;i<n;i++)
       {
           if(st.size()==0)
           {
               ngl.push_back(-1);
           }
           else if(st.size()>0 && st.top().first>arr[i])
           {
               ngl.push_back(st.top().second);
           }
           else if(st.size()>0 && st.top().first<=arr[i])
           {
               while(st.size()>0 && st.top().first<=arr[i])
               {
                   st.pop();
               }
               if(st.size()==0)
               {
                   ngl.push_back(-1);
               }
               else
               {
                   ngl.push_back(st.top().second);
               }
           }
           
           st.push({arr[i],i});
       }
       
       for(int i=0;i<n;i++)
       {
           ngl[i]=i-ngl[i];
       }
       
       return ngl;
    }
};
