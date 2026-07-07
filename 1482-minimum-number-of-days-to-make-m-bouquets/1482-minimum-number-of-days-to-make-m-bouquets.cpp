class Solution {
public:
    bool f(vector<int>&nums , int mid , int k , int m)
    {
        int total  = 0 ; 
        int cnt = 0; 
        for(int i : nums)
        {
            if(i<=mid)
            {
                cnt++;
            }
            else
            {
                total+=(cnt/k);
                cnt = 0 ; 
            }
        }
        total+=(cnt/k);
        return total>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        if(n*1LL<m*1LL*k) return -1;
        int low = 0 , high =  *max_element(nums.begin(),nums.end());
    while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(f(nums , mid , k , m))
            {
                high = mid - 1; 
            }
            else
            {
                low = mid +  1; 
            }
        }
        return low  ; 
    }
};