class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0 ;
        int ele = nums[0] ;
        int n = nums.size(); 
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]==ele)
            {
                cnt++;
            }
            else cnt--;
            if(cnt<0) {
                ele = nums[i];
                cnt = 0 ; 
            }
        }
        return ele;
    }
};