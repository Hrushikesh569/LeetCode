class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v;
        v.push_back(-1e9);
        for(int i = 0 ; i < n ; i++) 
        {
            if(nums[i]) v.push_back(i);
        }
        for(int i = 0 ; i < v.size()-1 ;i++)
        {
            if(v[i+1]-v[i]<=k) return 0;
        }
        return 1;
    }
};