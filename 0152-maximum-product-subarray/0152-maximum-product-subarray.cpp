class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans = nums[0];
        long long neg = nums[0];
        long long pos = nums[0];
        for(int i = 1 ; i < nums.size(); i++)
        {
            long long  pren = neg;
            long long prep = pos;
            pos = max({nums[i]*1LL,prep*nums[i],pren*nums[i]});
            neg = min({nums[i]*1LL,prep*nums[i],pren*nums[i]});
            ans = max({ans , pos , neg});
        }
        return ans ;
        }
};