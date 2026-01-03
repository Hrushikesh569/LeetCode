class Solution {
public:
    int m = 1e9+7;
    vector<string> v = {
    "rgb", "rbg",
    "grb", "gbr",
    "brg", "bgr",
    "rgr", "rbr",
    "grg", "gbg",
    "brb", "bgb"
};
    int solve(int n , int prev,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][prev]!=-1) return dp[n][prev];
        int ans= 0 ; 
        string last = v[prev];
        for(int i =0  ; i < 12 ;i++)
        {
            if(i==prev) continue;
            string cur = v[i];
            int flag = 1;
            for(int j = 0 ; j < 3 ; j++)
            {
                if(cur[j]==last[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                ans = (ans+solve(n-1 , i,dp))%m;
            }
        }
        return dp[n][prev] = ans;
    }
    int numOfWays(int n) {
        int ans = 0;
        vector<vector<int>>dp(5001,vector<int>(13,-1));
        for(int i = 0 ; i < 12 ; i++)
        {
            ans = (ans+solve(n-1,i,dp))%m;
        }
        return ans;
    }
};