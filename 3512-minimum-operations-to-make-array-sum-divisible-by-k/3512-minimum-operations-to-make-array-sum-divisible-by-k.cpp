class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for(auto i : nums) sum+=i;
        return (sum%k);
    }
};