class Solution {
public:
    int check(vector<int>&nums , long long mid , long long  n )
    {
        long long sum = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++)
        {
           sum+=(min(mid , 1LL*nums[i]));
        }
        return sum/mid>=(n*1LL)?1:0;
    }
    long long maxRunTime(int n, vector<int>& nums) {
        long long ans = 0 ; 
        
        long long  low = 1  , high = 1e15;
        while(low<=high)
        {
            long long mid = low + (high - low)/2;
            if(check(nums , mid , n))
            {
                ans = mid;
                low = mid+ 1; 
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};