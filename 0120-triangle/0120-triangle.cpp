class Solution {
public:
    int dfs(vector<vector<int>>&t,int i , int j,int n,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x = t[i][j]+dfs(t,i+1,j,n,dp);
        int y = 1000000;
        if(j<t[i].size())
        {
            y=t[i][j]+ dfs(t,i+1,j+1,n,dp);
        }
        return dp[i][j]=min(x,y);
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        if(n==0) return n;
      vector<int>dp=t[n-1];
      for(int i= n-2 ; i>=0 ; i--)
      {
        for(int j = 0 ; j<=i ; j++)
        {
            dp[j] = t[i][j]+min(dp[j],dp[j+1]);
        }
      }
      return dp[0];
    }
};