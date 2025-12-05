class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0; 
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ;i++)
        {
           sum+=nums[i];
        }
      
        return  sum&1?0:n-1;

    }
};