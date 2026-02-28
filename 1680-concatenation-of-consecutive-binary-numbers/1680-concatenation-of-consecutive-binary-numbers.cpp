class Solution {
public:
    int m= 1e9+7;
    int concatenatedBinary(int n) {
        long long ans = 0 ;
        long long bit = 1 ; 
        for(int i = n ; i>=1 ;i--)
        {
            long long temp = i ; 
            while(temp>0)
            {
                long long x = ((temp&1)*bit)%m;
                ans = (x+ans)%m;
                temp/=2;
                //if(temp>0)
                bit=(bit*2)%m;
            }
        }
        return ans ; 
    }
};