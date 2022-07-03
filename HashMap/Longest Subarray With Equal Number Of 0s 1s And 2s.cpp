int solution(vector<int> &v){
   //Write your code here
   int z0=0,z1=0,z2=0;
   int ans=0;
   unordered_map<string,int>mp;
   string exp = to_string(z1-z0) + '-' + to_string(z2-z1);
   mp[exp]=-1;
   for(int i=0;i<v.size();i++)
   {
       if(v[i]==0)
       z0++;
       else if(v[i]==1)
       z1++;
       else
       z2++;
       exp = to_string(z1-z0) + '-' + to_string(z2-z1);
       if(mp.find(exp)!=mp.find())
       {
           ans = max(ans,i-mp[exp]);
       }
       else
       {
           mp[exp]=i;
       }

   }
   return ans;
}
