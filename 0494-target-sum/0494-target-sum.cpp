class Solution {
public:
    vector<vector<int>>dp;
    vector<int>v;
    int n ;
    int offset ;
    int SIZE;
    int total = 0 ; 
    int dfs(int i  , int sum )
    {
        if(i==n)
        {
            return (sum==0);
        }
        int idx = sum + offset;
        if(idx<0 || idx>=SIZE) return 0 ; 
        if(dp[i][idx]!=-1) return dp[i][idx];
        int take = dfs(i+1 , sum - v[i]);
        int skip = dfs(i+1 , sum + v[i]);
        return dp[i][idx] = take + skip;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0 ; 
        n = nums.size();
        v = nums;
        for(auto  i : nums)total+=i;
        offset = total ; 
         SIZE = total*2+1;
        dp.assign(nums.size()+1,vector<int>(SIZE,-1));
        
        return dfs(0 , target);
    }
};