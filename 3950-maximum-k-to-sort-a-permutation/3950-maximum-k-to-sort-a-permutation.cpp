class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans =nums.size();
        for(int i= 0 ; i <nums.size()-1 ;i++)
        {
            if(nums[i]!=i)
            {
                ans = min(ans, nums[i]&i);
            }
        }
        if(nums.size()==ans)
        return 0;
        return ans;
    }
};