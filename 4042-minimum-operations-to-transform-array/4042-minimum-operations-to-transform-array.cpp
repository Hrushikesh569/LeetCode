class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0 ;
        int n  = nums1.size();
        long long temp = 1e9;
        long long val = 0;
        for(int i = 0 ; i < n ; i++)
        {
            ans +=abs(nums1[i]-nums2[i]);
            temp = min(temp,1LL*abs(nums1[i]-nums2[n]));
            temp = min(temp,1LL*abs(nums2[i]-nums2[n]));
            int sgn = (nums2[n]>=nums1[i]?1:-1);
            int sgn2 = (nums2[n]>=nums2[i]?1:-1);
            if(sgn*sgn2<0) temp = 0;
        }
       ;
        return ans+temp+1;
    }
};