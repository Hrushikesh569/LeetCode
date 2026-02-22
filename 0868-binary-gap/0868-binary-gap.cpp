class Solution {
public:
    int binaryGap(int n) {
        string s;
        while(n>0)
        {
            s+=((n&1)+'0');
            n>>=1;
        }
        int ans =0; 
        int cnt = 0 ; 
       cout<<s<<endl;
        for(int i = 0 ; i<s.size() ;i++)
        {
            if(s[i]=='1') 
            {
                int j = i+1;
                cnt = 1 ; 
                while(j<s.size() and s[j]=='0') 
                {
                  //  cout<<j<<" ";
                    cnt++;
                    j++;
                }
                if(j<s.size()) ans = max(ans,cnt);
           
            }
        }
  //      cout<<s;
        return ans ; 
    }
};