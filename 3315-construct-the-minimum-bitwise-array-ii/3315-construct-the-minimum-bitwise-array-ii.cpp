class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i < n ; i++)
        {
            
            if(nums[i]==2) 
            {
                ans.push_back(-1);
                continue;
            }
            
            for(int j = 0; j <32 ; j++)
            {
               if((nums[i]&(1<<j))>0) continue;
               int bit = (1<<(j-1));
               int x = nums[i]^bit;
               ans.push_back(x);
               
               break;
            }
           
           
        }
        return ans;
    }
};