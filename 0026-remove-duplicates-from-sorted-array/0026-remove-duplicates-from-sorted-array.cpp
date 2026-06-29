class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int st = 1 ; 
        int n = nums.size();
        while(st<n and nums[st-1]!=nums[st]) st++;
        if(st==n) return st;
        for(int i = st+1 ; i < n; i++)
        {
            if(nums[i]==nums[i-1]) continue;
            nums[st] = nums[i];
            st++;
        }
        return st;
    }
};