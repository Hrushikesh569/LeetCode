class Solution {
public:
    bool f(vector<int>&nums, int mid , int x)
    {
        int sum = 0 ;
        for(auto i : nums)
        {
            sum+=((i+mid - 1)/mid);
        }
        return sum<=x;
    }
    int smallestDivisor(vector<int>& nums, int x) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end())+1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(f(nums , mid , x))
            {
                high = mid - 1 ; 
            }
            else
            {
                low = mid + 1; 
            }
        }
        return low ;
    }
};