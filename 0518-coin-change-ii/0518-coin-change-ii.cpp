class Solution {
public:
    int change(int target, vector<int>& coins) {
        vector<vector<long long >>dp(coins.size(),vector<long long >(target+1));
        int n = coins.size();
        for(int i = 0 ; i < n; i++) dp[i][0] = 1; 
        for(int i = 0 ; i <= target;i++)
        if(i%coins[0]==0) dp[0][i] = 1;
        for(int i = 1 ; i < n; i++)
        {
            for(int j = 1 ; j <= target ; j++)
            {
                int take = 0 , skip = dp[i-1][j];
                if(j>=coins[i])
                {
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take+0LL+skip;
            }
        }
       return  dp[n-1][target];
    }
};