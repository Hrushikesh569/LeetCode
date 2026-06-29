class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxi = 0 ; 
        int mini = 1e9 ; 
        int n = nums.size();
        for(int i = 0 ; i < n; i++)
        {
            mini = min(mini , nums[i]);
            maxi = max(nums[i]-mini , maxi);
        }
        return maxi ; 
    }
};