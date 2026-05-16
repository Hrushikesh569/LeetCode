class Solution {
public:
    vector<int>dp;
    int dfs(vector<int>& nums ,  int cur)
    {
        if(cur>=nums.size()) return 0; 
        if(dp[cur]!=-1) return dp[cur];
        int x = INT_MIN;
        int y = INT_MIN;
        x = dfs(nums , cur+2)+nums[cur];
        y = dfs(nums , cur+1);
        return dp[cur] = max(x , y);
    }
    int rob(vector<int>& nums) {
        int ans = 0 ; 
        dp = vector<int>(nums.size()+1 , -1);
        return dfs(nums , 0 );
    }
};