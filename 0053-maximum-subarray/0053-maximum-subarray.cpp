class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur= nums[0];
        int maxi = nums[0];
        int n = nums.size();
        for(int i = 1 ;i < n ;i++)
        {
            cur = max(nums[i] , cur+nums[i]);
            maxi  = max(cur, maxi);
        }
        return maxi;
    }
};