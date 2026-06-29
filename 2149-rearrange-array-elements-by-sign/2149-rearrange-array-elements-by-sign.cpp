class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pv = 0 , nv = 1;
        vector<int>v(nums.size());
        for(int i = 0 ; i < nums.size() ;i++)
        {
            if(nums[i]>0) 
            {
                v[pv] = nums[i];
                pv+=2;
            }
            else
            {
                v[nv] = nums[i];
                nv+=2;
            }
        }
        return v;
    }
};