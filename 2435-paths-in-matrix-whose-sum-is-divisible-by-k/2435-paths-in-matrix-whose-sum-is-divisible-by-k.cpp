class Solution {
public:
   int mm = 1e9+7;
    int dfs(vector<vector<int>>&v , int i , int j , long long sum , int k, vector<vector<vector<int>>>&dp)
    {
        int n = v.size();
        int m = v[0].size();
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1)
        {
            if(sum%k==0)
            {
                return 1;
            }
            return 0;
        }
        int rem = (sum%k+k)%k;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        int ans = 0 ; 
        
        if(i+1<n)
        ans=(ans+(dfs(v , i+1 , j ,(sum+v[i+1][j]) , k,dp))%mm)%mm;
        if(j+1<m)
        ans= (ans+(dfs(v , i , j+1 , (sum+(v[i][j+1])) , k,dp))%mm)%mm;
        return dp[i][j][rem] =  ans;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k,-1)));
        return dfs(grid  , 0 , 0 ,1LL*grid[0][0],k,dp);
    }
};