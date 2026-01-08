class Solution {
public:
   
    int dfs(vector<int>&a , vector<int>&b,int i  , int j , int n ,int  m , vector<vector<int>>&dp)
    {
        if(i==n or j==m) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int take1  = a[i]*b[j];
        int take2 = take1+dfs(a,b,i+1,j+1,n,m,dp);
        int take3 = dfs(a,b,i+1,j,n,m,dp);
        int take4 = dfs(a,b,i,j+1,n,m,dp);
        return dp[i][j] = max({take1,take2,take3,take4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        int n = nums1.size();
        int m = nums2.size();
        return dfs(nums1, nums2,0 , 0 , n , m,dp);
    }
};