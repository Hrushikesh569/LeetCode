class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9+7;
        int n = nums.size();
        
        vector<long long> dp(n+1), pref(n+1);
        dp[0] = pref[0] = 1;

        deque<int> mx, mn;
        int l = 1;

        for(int r = 1; r <= n; r++) {
            int x = nums[r-1];

            while(!mx.empty() && nums[mx.back()] <= x) mx.pop_back();
            mx.push_back(r-1);
            while(!mn.empty() && nums[mn.back()] >= x) mn.pop_back();
            mn.push_back(r-1);
            while(!mx.empty() && !mn.empty() &&
                  nums[mx.front()] - nums[mn.front()] > k) {

                if(mx.front() == l-1) mx.pop_front();
                if(mn.front() == l-1) mn.pop_front();
                l++;
            }
            long long sum = pref[r-1];
            if(l-2 >= 0) sum = (sum - pref[l-2] + MOD) % MOD;

            dp[r] = sum;
            pref[r] = (pref[r-1] + dp[r]) % MOD;
        }

        return dp[n];
    }
};
