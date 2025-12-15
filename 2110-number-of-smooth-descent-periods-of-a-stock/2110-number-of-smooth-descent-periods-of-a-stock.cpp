class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1 ; 
        long long prev = 1;
        for(int i = 1 ; i < n ;i++)
        {
            if(prices[i-1]-1==prices[i])prev++;
            else prev = 1;
            ans+=prev;
        }
        return ans;

    }
};