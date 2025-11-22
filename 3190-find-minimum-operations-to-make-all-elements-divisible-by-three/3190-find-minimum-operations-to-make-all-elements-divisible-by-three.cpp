class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++)
        {
            ans+=(min(nums[i]%3,(3-nums[i]%3)));
        }
        return ans;
    }
};