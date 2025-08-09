class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=0;
        if(n<0) return false;
        while(n)
        {
            if(n&1==1) ans++;
            n>>=1;
        }
        return(ans==1);
    }
};