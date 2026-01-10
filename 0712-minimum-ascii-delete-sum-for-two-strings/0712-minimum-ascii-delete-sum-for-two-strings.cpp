class Solution {
public:
    int dfs(string &s1 , string &s2 , int i , int j , int n , int m,vector<vector<int>>&dp)
    {
        if(i>=n && j>=m)
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j>=m)
        {
            return dfs(s1,s2,i+1,j,n,m,dp)+s1[i];
        }
        if(i>=n)
        {
            return dfs(s1,s2,i,j+1,n,m,dp)+s2[j];
        }
        if(s1[i]==s2[j])
        {
            return dfs(s1,s2,i+1,j+1,n,m,dp);
        }
        return dp[i][j] = min(dfs(s1,s2,i+1,j,n,m,dp)+s1[i],dfs(s1,s2,i,j+1,n,m,dp)+s2[j]);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n= s1.size(),m= s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return dfs(s1,s2,0,0,s1.size(),s2.size(),dp);
        
    }
};