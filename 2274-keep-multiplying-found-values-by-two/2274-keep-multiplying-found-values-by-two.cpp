class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
       // int n = nums.size();
        unordered_set<int>v(nums.begin(),nums.end());
        int a = original;
        while(v.count(a))a*=2;
        return a;
    }
};