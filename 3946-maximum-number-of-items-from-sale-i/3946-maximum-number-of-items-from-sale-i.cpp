class Solution {
public:
    vector<vector<int>>dp;
    int mini = 1e9;
    int dfs(vector<vector<int>>&nums , vector<int>&v , int i  , int budget)
    {
        if(i>=nums.size()) return budget/mini ; 
        if(dp[budget][i]!=-1) return dp[budget][i];
        int not_take = dfs(nums,v ,  i+1 , budget);
        int take  = 0 ; 
        if(budget >= nums[i][1])
        {
            
            take = dfs(nums , v , i +1, budget-nums[i][1])+v[i];
        }
        return dp[budget][i] = max(take , not_take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int>v;
        mini= 1e9;
        int n = items.size();
        for(int i = 0 ; i < n ;i++)
        {
            int cnt = 0 ; 
            for(int j = 0 ; j < n ; j++)
            {
                mini = min(mini  , items[i][1]);
                cnt+=(items[j][0]%items[i][0]==0);
            }
            v.push_back(cnt);
        }
        dp.clear();
        dp = vector<vector<int>>(budget+1, vector<int>(n+1, -1));
       return dfs(items , v , 0 , budget);
        return 0;
    }
};