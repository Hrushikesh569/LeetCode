class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int ind  = 0;
        int mini = 51 ;
        for(int i = 1 ; i < nums.size() ;i++)
        {
            if(mini>=nums[i]){
                mini = nums[i];
                ind = i ; 
            }
        }  
        ans+=mini;
        mini = 51;
        int ind2 = 0 ; 
        for(int i =1 ; i < nums.size() ; i++)
        {
            if(ind!=i && mini>=nums[i])
            {
                mini = nums[i];
            }
        }
        ans+=mini;
        return ans;
    }
};