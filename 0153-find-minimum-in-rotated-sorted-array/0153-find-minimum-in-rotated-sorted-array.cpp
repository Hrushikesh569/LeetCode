class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n-1];
        int low  = 0 , high = n - 1;
        int ans = -1 ; 
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]>x)
            {
                ans = mid;
                low = mid + 1 ; 
            }
            else
            {
                high = mid - 1 ; 
            }
        }
        if(ans == -1 or n==1)return nums[0];
        return nums[ans+1];
    }
};