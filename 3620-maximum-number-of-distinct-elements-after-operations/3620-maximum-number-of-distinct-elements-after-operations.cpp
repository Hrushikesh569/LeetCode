class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long pm = INT_MIN;
        int cnt = 0;
        for(auto i : nums)
        {
            long long  lb = 1LL+i-k;
            long long  up = 1LL+i+k; 
            if(pm<lb)
            {
                cnt++;
                pm = lb;
            }
            else if(pm<up)
            {
               pm++;
                cnt++;
            }
        }
        return cnt;
    }
};