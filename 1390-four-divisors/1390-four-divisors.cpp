class Solution {
public:
    int m = 1e5+7;
    int mod = 1e9+7;
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int , unordered_set<long long >>mp;
        int n = nums.size();
        long long  ans = 0 ;
        for(int  i = 0 ; i < n ; i++)
        {
            int cnt = 0 ; 
            int val = 0 ; 
            for(int j = 2 ; j * j <= nums[i] ;j++)
            {
                if(nums[i]%j==0)
                {
                    val = j ; 
                    cnt++;
                    if(j*j==nums[i]) cnt++;
                }
            }
            if(cnt==1) 
                {
                    ans+=(val+(nums[i]/val));
                    ans+=1;
                    ans+=nums[i];
                }
        }
        return ans;
    }
};