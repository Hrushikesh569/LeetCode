class Solution {
public:

    
    int areaOfMaxDiagonal(vector<vector<int>>& nums) {
        long long large;
        large = 0;
        cout<<large;
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i <  n ; i++)
        {
            long long  temp = 1LL*(nums[i][0]*nums[i][0]+nums[i][1]*nums[i][1]);
            
            if(temp>large)
            {
                // cout<<nums[i][0]<<" "<<nums[i][1]<<endl;
                // cout<<temp<<endl;
                ans = (nums[i][0]*nums[i][1]);
                large = temp;
            }
            else if(temp==large)
            {
                ans= max(ans,nums[i][0]*nums[i][1]);
            }

        }
        return ans;
    }
};