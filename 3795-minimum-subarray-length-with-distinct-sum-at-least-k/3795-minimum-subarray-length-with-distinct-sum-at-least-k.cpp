
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
       int m = 1e9+7;
       int n = nums.size();
       int ans = m;
       int sum = 0 ;
       int back = 0 ; 
       for(int i = 0 ; i < n ;i++)
        {
            if(mp[nums[i]]==0)
            {
                sum+=nums[i];
            }
            mp[nums[i]]++;
            while(sum>=k)
            {
                ans = min(ans,i-back+1);
                mp[nums[back]]--;
                if(mp[nums[back]]==0)
                sum-=nums[back];
                back++;
            }
        }
        if(ans==m) return -1
;        return ans;
    }
};