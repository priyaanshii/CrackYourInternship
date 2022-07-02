#include<bits/stdc++.h>
using namespace std;
 
int solution(string str, int k) {
	// write your code here
    int ans=0;
    int distinct=0;
    int release=0;
    unordered_map<char,int>mp;
    for(int i=0;i<str.size();i++)
    {
        char curchar = str[i];

        if(mp.find(curchar)!=mp.end())
        {
            mp[curchar]++;
        }
        else
        {
            mp[curchar]=1;
            distinct++;
        }

        while(release<=i && distinct>k)
        {
            char dischar = str[release];
            mp[dischar]--;
            release++;
            if(mp[dischar]==0)
            {
                mp.erase(dischar);
                distinct--;
            }
            
        }
        ans = ans + (i-release+1);
    }
    return ans;
}

int main() {
    string str;
    int k;
    cin >> str >> k;
	cout << solution(str,k);
}
//question link -> https://nados.io/question/count-of-substrings-having-at-most-k-unique-characters?zen=true
