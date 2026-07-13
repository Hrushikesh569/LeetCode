class Solution {
public:
    int total = 0 ; 
    bool dfs(int i , int sum , vector<int>&v)
    {
        if(i==v.size())
        {
            return (sum*2==total);
        }
        int take = 0 ; 
        if(sum*2<=total)
        take = dfs(i+1 , sum+v[i] , v);
        int not_take = dfs(i+1,sum,v);
        return (take or not_take);

    }
    bool canPartition(vector<int>& nums) {
        total = 0 ; 
        for(auto i : nums)total+=i;
        if(total%2) return 0 ; 
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(total/2+1));
        dp[n][total/2] = 1;
        for(int i = n - 1; i >=0  ; i--)
        {
            int sum = 0; 
            for(int sum  = 0 ; sum<=total/2 ; sum++)
            {
                int take = 0 ; 
                int not_take =  0 ; 
                if((sum+nums[i])<=total/2)
                take = dp[i+1][sum+nums[i]];
                not_take  = dp[i+1][sum];
                dp[i][sum] = take or not_take;
            }
        }
        return dp[0][0];
        
    }
};