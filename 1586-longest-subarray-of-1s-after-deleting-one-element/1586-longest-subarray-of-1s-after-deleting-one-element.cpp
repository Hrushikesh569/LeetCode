class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n),suf(n);
        if(nums[0]) pre[0] = 1;
        for(int i = 1 ; i< n ; i++)
        {
            if(nums[i])
            {
                pre[i] = pre[i-1]+1;
            }
        }
        if(nums[n-1]) suf[n-1]=1;
        for(int i = n-2 ; i>=0 ; i--)
        {
            if(nums[i])
            {
                suf[i] = suf[i+1]+1;
            }
        }
        int maxi = *max_element(pre.begin(),pre.end());
        if(n<3) return min(maxi,n-1);
        for(int i = 1 ; i < n-1 ; i++)
        {
            maxi = max(pre[i-1]+suf[i+1],maxi);
        }
        // for(auto i: pre)cout<<i<<" ";
        // cout<<endl;
        // for(auto i: suf)cout<<i<<" ";
        return min(maxi,n-1);
    }
};