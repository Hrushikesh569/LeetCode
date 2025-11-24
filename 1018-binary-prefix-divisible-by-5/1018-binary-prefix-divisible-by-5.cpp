class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        long long  val = 0;
        for(int i = 0 ; i < nums.size(); i++)
        {
            val<<=1;
            val |= (nums[i]==1?1:0);
            if(val%5)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(1);
            }   
            val%=5;
                
        }
        return ans;
    }
};