class Solution {
public:
    vector<vector<int>>dp;
    int maximumJumps(vector<int>& nums, int target) {
         int n = nums.size();
        dp = vector<vector<int>>(n+1 , vector<int>(n+1,0));
    //     int ans = dfs(nums , 0 , 1 , target);
    //    if(ans>=0) return ans ; 
      for(int i = 0 ; i < n ; i++)
    {
        dp[i][n] = -1e9;
    }
       dp[n-1][n] = 0 ; 
       for(int prev = n -1 ; prev >=0 ; prev--)
       {
        for(int cur = n - 1; cur> prev ;cur--)
        {
            int not_take = dp[prev][cur+1];
            int take = -1e9;
            if(abs(nums[prev]-nums[cur])<=target)
            {
                take = dp[cur][cur+1]+1;
            }
            dp[prev][cur] = max(take , not_take);
        }
       }
       return dp[0][1]>=0?dp[0][1]:-1;
        
    }
};