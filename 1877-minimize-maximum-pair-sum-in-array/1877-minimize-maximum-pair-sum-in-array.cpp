class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0 , j=  nums.size()-1;
        int maxi =0 ; 
        for(; i <=j ; i++,j--)
        {
            maxi = max(maxi , nums[i]+nums[j]);
        }
        return maxi;
    }
};