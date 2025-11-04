#define p pair<int,int>
class Solution {
public:
    int fun(unordered_map<int,int>mp,int x)
    {
        priority_queue<p, vector<p>, greater<p>> h;
        for(auto [key,val]:mp)
        {
            h.push({val,key});
            if(h.size()>x)
            {
                h.pop();
            }
        }
        int sum = 0;
        while(!h.empty())
        {
            auto [q,w] = h.top();
            h.pop();
            sum+=(q*w);
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        int i = 0 , j = 0;
        while(j<n )
        {
            mp[nums[j]]++;
            if(j-i+1==k)
            {
                ans.push_back(fun(mp,x));
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return  ans;
    }
};