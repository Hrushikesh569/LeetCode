class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(auto &i : nums) 
        if(i==val){ 
        i = 101;
        k++;
        }
        sort(nums.begin(),nums.end());
        return nums.size()-k;

    }
};