class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];
        vector<long long> minPref(k, LLONG_MAX);
        minPref[0] = 0; 

        long long ans = LLONG_MIN;

        for (int r = 1; r <= n; r++) {
            int rem = r % k;

            if (minPref[rem] != LLONG_MAX)
                ans = max(ans, pref[r] - minPref[rem]);

            minPref[rem] = min(minPref[rem], pref[r]);
        }

        return ans;
    }
};
