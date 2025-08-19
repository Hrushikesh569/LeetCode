class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long>p(n);
        p[0] = (nums[0]==0);
        
        for(int i = 1 ; i < n ; i++)
        {
            
            if(nums[i]==0)
            p[i] = 1LL*p[i-1]+(nums[i]==0);
        }
        long long cnt = 0;
        for(auto i : p)cnt=1LL*cnt+i;
        return cnt;

        
    }
};