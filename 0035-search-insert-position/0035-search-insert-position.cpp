class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = -1;
        int high = nums.size();
      //  int ans =high+1 ; 
        while(high-low>1)
        {
            int mid = low + (high - low)/2;
            if(nums[mid]>=target)
            {
                high = mid ; 
              //  ans = mid;
            }
            else
            {
                low = mid ;
            }
        }
        return high;
    }
};