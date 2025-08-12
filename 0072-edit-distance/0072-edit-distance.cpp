class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word2.size(), m = word1.size();
          vector<vector<int>>dp(n+1 , vector<int>(m+1 , 501));
          int mini = 502;
          for(int i = 0 ; i <= n ; i++)
          {
            dp[i][0] = i;
          }
          for(int i = 0 ; i <=m ; i++)
          {
            dp[0][i] = i;
          }
          dp[0][0] = 0;
          for(int i = 1 ; i <= n ; i++)
          {
            for(int j = 1 ; j <= m ; j++)
            {
                int mini = min({ dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1] });
                if(word2[i-1] != word1[j-1])
                {
                    dp[i][j] = mini+1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
          }
          return dp[n][m];
    }
};