class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int flag = 0 ; 
        int cnt = 0 ;
        for(int i = 0 ; i < n -1 ; i++)
        {
            if(nums[i]>nums[i+1])
            {
                flag++;
                break;
            }
        }
        if(!flag) return 0;
        int ans = 0 ; 
        while(nums.size()>1)
        {
            int ind = 0 ;
            int sum  = 1e9;
            for(int i = 0 ; i < nums.size() -1 ; i++)
            {
                if(sum>(nums[i]+nums[i+1]))
                {
                    sum = nums[i]+nums[i+1];
                    ind = i ; 
                }
            }
            nums[ind] = sum;
            int flag = 0 ; 
            cnt++;
            nums.erase(nums.begin()+ind+1);
            for(int i = 0 ; i < nums.size() -1 ; i++)
            {
                if(nums[i]>nums[i+1])
                {
                    flag = 1 ; 
                    break;
                }
            } 
            if(!flag)
            {
                return cnt;
            }
        }
       return cnt;
    }
};