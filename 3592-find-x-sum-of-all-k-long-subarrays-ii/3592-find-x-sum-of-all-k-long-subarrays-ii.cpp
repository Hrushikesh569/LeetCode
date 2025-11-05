
class Solution {
public:
    long long sum;
    set<pair<int,int>>main;
    set<pair<int,int> >temp;
    int z ;
    void is(pair<int,int>p)
    {
        int flag = p>(*main.begin());
        if(main.size()<z || flag)
        {
            main.insert(p);
            sum+=(1LL*p.first*p.second);
            if(main.size()>z)
            {
                auto small = *main.begin();
                sum-=(1LL*small.first*small.second);
                main.erase(small);
                temp.insert(small);
            }
        }
        else
        {
            temp.insert(p);
        }
    }
    void rfs(pair<int,int>&p)
    {
        if(main.find(p)!=main.end())
        {
            sum-=(1LL*p.first*p.second);
            main.erase(p);
            if(!temp.empty())
            {
                auto large = *temp.rbegin();
                temp.erase(large);
                main.insert(large);
                sum+=(1LL*large.first*large.second);
            }
        }
        else
        {
            temp.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n ;
        vector<long long >ans;
        sum = 0;
        z = x;
        int i = 0 , j = 0 ;
        n = nums.size();
        unordered_map<int,int>mp;
        while(j<n)
        {
            if(mp[nums[j]]>0)
            {
                pair<int,int>a = {mp[nums[j]],nums[j]};
                rfs(a);
            }
            mp[nums[j]]++;
            is({mp[nums[j]],nums[j]});
            if(j-i+1==k)
            {
                ans.push_back(sum);
                pair<int,int>b = {mp[nums[i]],nums[i]};
                rfs(b);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                else is({mp[nums[i]],nums[i]});
                i++;
            }
            j++;
        }
        return ans;
    }
};