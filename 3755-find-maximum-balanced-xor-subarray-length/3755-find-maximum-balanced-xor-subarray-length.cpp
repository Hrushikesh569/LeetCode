class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        map<pair<long long,int>,int>mp;
        int bal = 0 ;
        long  long xr = 0 ; 
        mp[{0 , 0 }] = -1;
        int ans = 0 ; 
        for(int i = 0 ; i < nums.size() ;i++)
        {
            xr^=nums[i];
            if(nums[i]&1) bal++;
            else bal--;
            pair<int,int> k = {xr,bal};
            if(mp.count(k))
            {
                ans = max(ans , i-mp[k]);
            }
            else
            {
                mp[k] = i;
            }
        }
        return ans;
    }
};