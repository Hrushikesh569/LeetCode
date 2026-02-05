class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++)
        {
            int ind = i ; 
            if(nums[i]>0)
            {
                ind = (i+nums[i])%n;
              //  cout<<ind<<" ";
            }
           else if(nums[i]<0)
            {
                ind = (i - (abs(nums[i])%n) + n)%n;
               // cout<<ind<<" ";
            }
            else
            {
                ind = i ; 
            }
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};