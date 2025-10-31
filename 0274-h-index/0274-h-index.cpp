class Solution {
public:
    int hIndex(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int maxi = 0;
       int n =  nums.size();
       for(int i = 1 ; i<=5000 ; i++)
       {
        int cnt = 0;
            for(int j = 0; j < n ; j++)
            {
                if(nums[j]>=i)
                {
                    cnt++;
                }
            }
            if(cnt>=i)
            maxi = max(i,maxi);
       }
        return maxi;
    }
};