class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i = 0 ;i < n; i++)
        {
            for(int j = 0 ; j < i  ; j++)
            {
                swap(nums[i][j],nums[j][i]);
            }
        }
        for(int i= 0 ; i < n ; i++)
        {
            reverse(nums[i].begin(),nums[i].end());
        }
        //return nums;
    }
};