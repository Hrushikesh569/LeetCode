class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0 ; 
        unordered_map<int , int>mp;
        int sum = 0 ; 
        int n = nums.size();
        mp[0] = 1;
        for(int i = 0; i < n ; i++)
        {
            sum+=nums[i];
            int val  = sum - k ; 
            if(mp.count(val))
            {
                ans+=mp[val];
            }
            mp[sum]++;
        }
        return ans ;
    }
};