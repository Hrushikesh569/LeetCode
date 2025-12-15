class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long >v(n,1);
        long long ans = 1  ; 
        for(int i = 1 ; i < n ;i++)
        {
            v[i]+=(prices[i-1]-1==prices[i])?v[i-1]:0;
            ans+=v[i];
        }
        return ans;

    }
};