class Solution {
public:
    int numWaterBottles(int n, int m) {
        int ans = n;
        while(n>=m)
        {
            int temp = n/m;
            ans+=temp;
            temp +=n%m;
          
            n=temp;          //3 + 3
        }
        return ans;
    }
};