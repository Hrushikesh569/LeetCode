class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        vector<int>v(n+1),dp(n+1);
        for(auto i : nums)
        {
            v[i]+=i;
        }
        if(n==1) return v[nums[0]];
        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);
        for(int i = 2; i <= n ; i++)
        {
            dp[i] = max(dp[i-2]+v[i] , dp[i-1]);
        }
        return dp[n];
    }
};