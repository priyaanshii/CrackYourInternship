class Solution {
public:

   bool isVowel(char c)
   {
     if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
     {
       return true;
     }

     else 
     {
       return false;
     }
   }
    int maxVowels(string s, int k) {
        int ans=0;
        int i=0,j=0;
        int n=s.size();

        int count=0;

        while(j<n)
        {
          if(isVowel(s[j]))
          {
              count++;
          }

          if(j-i+1<k){
            j++;
          }
          
          else if(j-i+1==k){
            ans=max(ans,count);
            if(isVowel(s[i])){
              count--;
            }
            i++;
            j++;
          }
        }

        return ans;
    }
};
