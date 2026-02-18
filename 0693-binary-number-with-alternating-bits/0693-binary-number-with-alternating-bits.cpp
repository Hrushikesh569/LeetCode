class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bi ;
        while(n>0)
        {
            char x = (n&1)+'0';
            n>>=1 ; 
            bi+=(x);
        }
        for(int i = 0 ; i < bi.size() - 1; i++)
        {
            if(bi[i]==bi[i+1]) return 0 ; 
        }
        return 1 ; 
    }
};