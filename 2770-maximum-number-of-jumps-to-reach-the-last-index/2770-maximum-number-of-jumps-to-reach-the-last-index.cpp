class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<int>&nums , int prev , int cur , int target)
    {
        int n = nums.size();
        if(prev == n - 1 and cur >= n ) return 0;
        if(cur>=n) return -1e9;
        if(dp[prev][cur]!=-1) return dp[prev][cur];
        int take = -1e9;
        int not_take  = dfs(nums , prev, cur+1 , target);
        if(abs(nums[cur]-nums[prev])<=target)
        {
            take = dfs(nums , cur , cur+1 , target)+1;
        }
        return dp[prev][cur] = max(take , not_take);
    }
    int maximumJumps(vector<int>& nums, int target) {
         int n = nums.size();
        dp = vector<vector<int>>(n+1 , vector<int>(n+1,-1));
        int ans = dfs(nums , 0 , 1 , target);
       if(ans>=0) return ans ; 
       return -1;
        
    }
};