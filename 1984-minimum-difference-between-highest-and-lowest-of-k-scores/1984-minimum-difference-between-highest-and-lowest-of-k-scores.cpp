class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size()<2) return 0 ; 
        sort(nums.begin(),nums.end());
        int mini = 123456; 
        cout<<nums.size()-k<<endl;
        for(int i = 0 ; i+k <= nums.size() ; i++)
        {
            mini = min(mini , (nums[i+k-1]-nums[i]));
        }
        return mini;
    } //1 4 7 9 
}; 