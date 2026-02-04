class Solution {
public:
    #define l LLONG_MIN
    #define ll long long 
    int n ;
    ll dfs(int i , int trend , vector<int>& nums,vector<vector<ll>>&dp)
    {
        if(i==n)
        {
            if(trend==3) return 0 ; 
            return l/2;
        }
        if(dp[i][trend]!=-1) return dp[i][trend];
        ll take = l/2;
        ll skip = l/2;
        if(trend==0)
        {
            skip = dfs(i+1,trend,nums,dp);
        }
        if(trend==3)
        {
            take = nums[i];
        }
        if(i+1<n)
        {
            ll cur = nums[i];
            ll next = nums[i+1];
            if(trend==0 && cur<next)
            {
                take = max(take,cur+dfs(i+1,1,nums,dp));
            }
            else if(trend==1)
            {
                if(cur<next)
                {
                    take = max(take,cur+dfs(i+1,1,nums,dp));
                }
                else if(cur>next)
                {
                    take = max(take,cur+dfs(i+1,2,nums,dp));
                }
            }
            else if(trend==2)
            {
                if(cur>next)
                {
                    take = max(take, cur+dfs(i+1 , 2 ,  nums,dp));
                }
                else if(cur<next)
                {
                    take = max(take , cur+dfs(i+1 , 3  , nums,dp));
                }
            }
            else if(trend==3)
            {
                if(cur<next)
                {
                    take = max(take , cur+dfs(i+1 , 3 , nums,dp));
                }
            }
        }
        return dp[i][trend] = max(skip , take);
    }
    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();
        vector<vector<ll>>dp(n+1,vector<ll>(4,-1));
        
        ll ans = dfs(0,0,nums,dp);
        return ans  ; 
    }
};