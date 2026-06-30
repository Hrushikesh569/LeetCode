class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        v.push_back({nums[0][0],nums[0][1]});
        for(int i = 1 ; i < nums.size() ;i++)
        {
            int x = nums[i][0];
            int y = nums[i][1];
            if(x<=v.back()[1])
            {
                v.back()[1] = max(nums[i][1],v.back()[1]);
            }
            else
            v.push_back({x,y});
        }
        return v;
    }
};