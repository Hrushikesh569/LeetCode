class Solution {
public:
    bool checkSubarraySum(vector<int >& nums, int k) {
        int n = nums.size();
        unordered_map<long long ,int>mp;
       mp[0] = -1 ; 
        long long  sum = 0 ; 
        for(int i = 0;  i <  n ;i++)
        {
            sum+=nums[i];
            int rem = sum%k;
            if(mp.count(rem))
            {
                if(i-mp[rem]>=2)
                {
                    return 1;
                }
                
            }
            else
                {
                    mp[rem]= i ; 
                }
        }
        return 0; 
    }
};