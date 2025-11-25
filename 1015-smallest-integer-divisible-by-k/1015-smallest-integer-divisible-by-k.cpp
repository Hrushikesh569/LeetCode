class Solution {
public:
    int smallestRepunitDivByK(int k) {
     if(gcd(k,10*1LL)!=1) return -1;
     long long  ans = 0 ; 
     for(long long  i = 1 ; i <= k ; i++)
     {
        ans = (ans*1LL*10+1)%k;
        if((ans)==0)
        {
            return i;
        }
     }
     return -1;
    }
};