class Solution {
public:
    bool p(string &s)
    {
        int n = s.size();
        for(int i = 0 ; i < n / 2 ; i++)
        {
            if(s[i]!=s[n-i-1]) return 0 ; 
        }
        return 1 ; 
    }
    int minOperations(string s) {
        int ans = 1e9 ; 
        if(p(s)) return 0 ; 
        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            // a - > c  z -> b (25 + b + 1 - 'a' + 1)%26
            int n = s.size();
            string x = s.substr(1);
            x+=s[0];
            int cost = i; 
            for(int i = 0  ; i < n/2 ; i++)
            {

                int val =  1e9;
                int j = n - i - 1 ; 
                val = abs(s[i] - s[j]);
                val = min(val  , 26 - val);
                cost += val;
            }
            ans =  min(ans  , cost);
            s = x;
        }
        return ans ; 
    }
};