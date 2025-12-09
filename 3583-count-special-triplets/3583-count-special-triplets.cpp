class Solution {
public:
    int specialTriplets(vector<int>& nums) {
    unordered_map<int,int>suffix , prefix;
        for(int i :nums)
            suffix[i]++;
        int n = nums.size();
        int cnt = 0;
        const int m = 1e9+7;
        for(int i = 0 ; i < nums.size() ; i++)
            {
                int x = nums[i];
                suffix[x]--;
                int k_cnt = suffix[2*x];
                int i_cnt = prefix[2*x];
                prefix[x]++;
                int z = (1ll*i_cnt*k_cnt)%m;
                cnt = (cnt+z)%m;
            }
        return cnt;
    }
};