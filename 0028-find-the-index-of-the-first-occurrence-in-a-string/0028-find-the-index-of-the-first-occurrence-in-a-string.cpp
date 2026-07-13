class Solution {
public:
    vector<int> build(string &s)
    {
        int n = s.size();
        vector<int>v(n);
        int len = 0 , i =  1 ; 
        while(i<n)
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
                i++;
            }
        }
        return v;
    }
    int strStr(string s, string t) {
        vector <int> lps = build( t);
        int i = 0 ; 
        int n= s.size();
        int m = t.size();
        int j = 0 ; 
        while(i < n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            if(j==t.size()) return ( i - t.size() );
            else if(i < n and s[i]!=t[j])
            {
                if(j!=0)
                {
                     j = lps[j - 1];
                }
                else
                 i++;
            }
        }
        return -1;
    }
};