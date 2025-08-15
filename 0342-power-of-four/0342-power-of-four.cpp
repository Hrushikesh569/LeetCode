class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        while(n%4==0) n/=4;
        n= abs(n);
        return (n==1);
    }
};