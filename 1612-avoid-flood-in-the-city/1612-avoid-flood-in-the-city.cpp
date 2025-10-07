class Solution {
public:
    vector<int> avoidFlood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        set<int>st;
        vector<int>ans(n,1);
        for(int i =0 ; i< n ; i++)
        {
            if(nums[i]==0)
            {
                st.insert(i);
            }
            else
            {
                if(mp.find(nums[i])!=mp.end())
                {
                    auto x = st.upper_bound(mp[nums[i]]);
                    if(x!=st.end())
                    {
                        ans[*x]=nums[i];
                        st.erase(x);
                    }
                    else
                    {
                        return {};
                    }
                }
                
                    ans[i] = -1;
                    mp[nums[i]] = i;
            }
        }
        return ans;
    }
};