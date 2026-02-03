class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n==3)
        {
            return 0;
        }
        int i = 0 , j = n -1 ; 
        for(; i< n - 1; i++)
        {
            if(nums[i]>=nums[i+1]) break;
        }
        for(;j>=1 ;j--)
        {
            if(nums[j-1]>=nums[j])
            break;
        }
     //   cout<<i<<" "<<j<<endl;
        if(i>=j || i==0 || j==n-1) return 0;
        for(int st = i ; st < j ; st++)
        {
            if(nums[st]<=nums[st+1]) return 0 ;
        }
        return 1;
    }
};