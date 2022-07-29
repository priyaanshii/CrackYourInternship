class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
            vector<string>ans;
            for(int i=0;i<words.size();i++)
            {
                    if(isMatches(words[i],pattern))
                            ans.push_back(words[i]);
            }
            
            return ans;
    }
    bool isMatches(string words,string pattern)
    {
            unordered_map<char,char>wmap,pmap;
            
            for(int i=0;i<words.size();i++)
            {
                    char c1 = words[i];
                    char c2 = pattern[i];
                    if(wmap.find(c1)!=wmap.end() && wmap[c1]!=c2 || pmap.find(c2)!=pmap.end() && pmap[c2]!=c1)  return false;
                    wmap[c1]=c2;
                    pmap[c2]=c1;
                    
            }
            
            return true;
    }
};
