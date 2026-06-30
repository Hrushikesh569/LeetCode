class Solution {

public:
    int mod = 1e9+7;
    vector<vector<int>> fourSum(vector<int>& nums, long long  target) {
        vector<vector<int>>ans; 
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i < n; i++)
        {
            if(i>0 and  nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j = i+1 ; j < n; j++)
            {
                if(j >i+1 and  nums[j]==nums[j-1]) continue;
                int k = j + 1 , l = n - 1 ; 
                while(k<l)
                {
                    long long  val=nums[i];
                    val=( val+ nums[j]);
                    val=( val+ nums[k]);
                    val=( val+ nums[l]);
                    if(val>target)
                    {
                        l--;
                    }
                    else if(val<target) k++;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++ , l--;
                        while(k<l and nums[k]==nums[k-1]) k++;
                        while(l>k and nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};