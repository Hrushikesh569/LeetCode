class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,1);
        v[0] = 1;
        int ans = 0;
        vector<int>v2(n,1);
        v2[n-1] = 1;
        for(int i = 1 ; i < n ; i++)
            {
                if(nums[i-1]<=nums[i]) v[i]+=(v[i-1]);
              
            }
        for(int i = n-2;  i>=0 ; i--)
            {
                if(nums[i+1]>=nums[i]) v2[i]+=(v2[i+1]);
            }
        // for(auto i : v) cout<<i<<" ";
        // cout<<endl;
        // for(auto i : v2) cout<<i<<" ";
        for(int i = 1 ; i < n -1 ; i++)
        {
            if(nums[i-1]<=nums[i+1])
            ans = max(v[i-1]+v2[i+1]+1,ans);
        }
        int x = (*max_element(v.begin(),v.end()));
        if(x<n) x++;

        return max(ans,x);
        
    }
};