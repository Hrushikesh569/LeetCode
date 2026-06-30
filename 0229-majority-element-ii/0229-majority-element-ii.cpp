class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = 1 ; 
        vector<int>ans;
        if(nums.size()<2) return nums;
        if(nums.size()==2 and nums[0]!=nums[1]) return nums;
        for(int i  = 1 ; i < nums.size(); i++)
        {
            if(nums[i]!=nums[i-1])
            {
                maxi  = 1 ;
            }
            else
            {
                maxi++;
            }
            if(maxi>nums.size()/3 and (ans.empty() or ans.back()!=nums[i])) {
                ans.push_back(nums[i]);
            }
        }
        return ans;

    }
};