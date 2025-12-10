class Solution {
public:
    int M = 1e9+7;
    int countPermutations(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        sort(nums.begin(),nums.end());
        if(x!=nums[0] || (nums[1]==x && nums[0]==x)) return 0;
        n--;
        vector<long long > fib(n+1);
        fib[0] = 1;
        for(long long  i = 1 ; i <= n ;i++)
        {
            fib[i] = (fib[i-1]*i)%M; 
        }
        return fib[n];
    }
};