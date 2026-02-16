class Solution {
public:
    int reverseBits(int n) {
        string s;
        while(n>0)
        {
            int bit = n%2;
            s+=(bit+'0');
            n/=2;
        }
        while(s.size()<32)
        {
            s+='0';
        }
        int val = 1 ; 
        int ans = 0 ; 
        for(int i = s.size()-1;i>=0 ; i--)
        {
            ans+=((s[i]-'0')*val);
            val<<=1;
        }
       // cout<<s;
        return ans ; 
    }
};