class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto &val:nums)
        {
            int  x = - 1; 
            for(int i = 0 ; i <=1000 ;i++)
            {
                if(val==(i | i+1))
                {
                    x = i;
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};