class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n),suf(n);
        pre[0] = nums[0];
        for(int i = 1 ; i < n ; i++)
            {
                pre[i] = max(pre[i-1],nums[i]);
            }
        suf[n-1] = nums[n-1];
        for(int i = n-2 ; i>= 0 ; i--)
            {
              suf[i] = max(suf[i+1],nums[i]);
            }
        // for(auto i: pre)cout<<i<<" ";
        // cout<<endl;
        // for(auto i : suf)cout<<i<<" ";
        int cnt = 0;
        for(int i = 1 ; i < n-1 ; i++)
            {
                if(pre[i-1]==pre[i] && suf[i]==suf[i+1])
                {
                    cnt++;
                }
            }
        return cnt;
    }
};