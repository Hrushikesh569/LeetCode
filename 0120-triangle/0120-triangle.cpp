class Solution {
public:
    // int dfs(int i ,int j , vector<vector<int>>&nums)
    // {
    //     if(i == nums.size()-1)
    //     {
    //         return nums[i][j];
    //     }
    //     int c = 1e9 , next = 1e9;
        
    //     next =  dfs(i+1 , j+1,  nums);
    //     c = dfs(i+1 , j,nums);
        
    //     return min(next , c)+nums[i][j] ; 
    // }
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+2));
        for(int i = n - 1;  i >= 0 ; i--)
        {
            dp[n-1][i] = nums[n-1][i];
        }
        for(int i = n - 2 ; i>= 0 ; i--)
        {
            for(int j = i ; j>=0 ; j--)
            {
                dp[i][j] = min(dp[i+1][j+1],dp[i+1][j])+nums[i][j];
            }
        }
        // for(auto i : dp)
        // {
        //     for(auto j: i)cout<<j<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};