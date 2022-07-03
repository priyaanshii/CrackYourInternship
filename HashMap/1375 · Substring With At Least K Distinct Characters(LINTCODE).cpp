class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
long long atMostKDistinctCharacters(string str, int k) {
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
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        long long n = s.size();
        return (n * (n + 1) / 2) - atMostKDistinctCharacters(s, k - 1);
    }
};
