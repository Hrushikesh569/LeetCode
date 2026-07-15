    class Solution {
    public:
        // int dfs(int i , int target , vector<int>&nums)
        // {
        //     if(i==0)
        //     {
        //         if(target%nums[0]==0)
        //         return target/nums[0];
        //         return 1e8;
        //     }
        //     int not_take = dfs(i-1 , target , nums);
        //     int take = 1e8;
        //     if(nums[i]<=target)
        //     {
        //         take = dfs(i , target - nums[i], nums)+1;
        //     }
        //     return min(take , not_take);
        // }
        int coinChange(vector<int>& nums, int target) {
            int n = nums.size();
           // vector<vector<int>>dp(n+1 , vector<int>(target+1,1e8));
            vector<int>prev(target+1,1e8),cur(target+1,1e8);
            for(int i = 0 ; i <=target;i++)
            {
                if(i%nums[0]==0)
                {
                    prev[i] = i/nums[0];
                }
            }
            for(int i = 1 ; i <n ; i++)
            {
                for(int j  = 0 ; j<=target ; j++)
                {
                    int take  = 1e8;
                    if(j>=nums[i])
                    take = cur[j-nums[i]]+1;
                    int not_take = prev[j];
                    cur[j] = min(take , not_take);
                }
                prev = cur;
            }
            if(prev[target]==1e8) return -1;
            return prev[target];
        }
    };