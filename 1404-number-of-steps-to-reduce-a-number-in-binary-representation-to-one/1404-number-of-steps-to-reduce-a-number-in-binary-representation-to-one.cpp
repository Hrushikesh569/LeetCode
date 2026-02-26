class Solution {
public:
    #define ll long long 
    int numSteps(string s) {
       int cnt = 0; 
       int n = s.size();
       if(n==1) return s[0]!='1';
       while(n>1)
       {
           n = s.size();
           if(s[n-1]=='0') 
           {
            s.pop_back();
           }
           else
           {
                int i = s.size() - 1; 
                while(i>=0 and s[i]!='0')
                {
                    s[i] = '0';
                    i--;
                }
                if(i<0)
                {
                    s = '1' + s;
                }
                else
                {
                    s[i]  = '1';
                }
           }
           cnt++;
       }
       return cnt-1;
    }
};