class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = 0 ; 
        vector<int>v(s.size(),0);
        int i = 1 ; 
        while(i<s.size())
        {
            if(s[i]==s[len])
            {
                len++;
                v[i] = len ; 
                i++;
            }
            else if(len!=0)
            {
                len = v[len - 1];
            }
            else
            {
            //    v[len] = 0 ; 
                i++;
            }
        }
        int ind = v[s.size()-1];
        return (ind > 0 and s.size()%(s.size()  - ind )==0);
        
    }
};