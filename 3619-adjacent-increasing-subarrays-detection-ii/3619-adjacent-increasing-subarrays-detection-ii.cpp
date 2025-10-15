class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int>v(nums.size(),1);
        int n = nums.size();
        vector<int>v2(nums.size(),1);
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i-1]<nums[i])
            {
                v[i] = v[i-1]+1;
            }         
        }
         for(int i = n-2 ; i >= 0  ; i--)
        {
            if(nums[i+1]>nums[i])
            {
                v2[i] = v2[i+1]+1;
            }         
        }
        // for(auto i : v) cout<<i<<" ";
        // cout<<"\n";
        // for(auto i : v2)cout<<i<<" ";
        int ans = *max_element(v.begin(),v.end())/2;
        for(int i= 0 ; i< n -1 ; i++)
        {
            ans = max(ans , min(v[i],v2[i+1]));
        }
        return ans;
    }
};