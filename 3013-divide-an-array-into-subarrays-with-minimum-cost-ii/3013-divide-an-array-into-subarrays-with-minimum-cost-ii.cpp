class Solution {
public:
    #define ll long long 
    #define P pair<ll,ll>
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<P>mini;
        set<P>rem;
        ll ans =  1e18+7;
        ll sum =  0  ; 
        int i = 1 ; 
        while(i-dist<1)
        {
            mini.insert({nums[i],i});
            sum+=nums[i];
            if(mini.size()>k-1)
            {
                P temp = *mini.rbegin();
                rem.insert(temp);
                sum-=temp.first;
                mini.erase(temp);
            }
            i++;
        }
        while(i<n)
        {
            mini.insert({nums[i],i});
            sum+=nums[i];
            if(mini.size()>k-1)
            {
                P temp = *mini.rbegin();
                rem.insert(temp);
                sum-=temp.first;
                mini.erase(temp);
            }
            ans = min(ans,sum);
            P remove = {nums[i-dist],i-dist};
            if(mini.count(remove))
            {
                mini.erase(remove);
                sum-=remove.first;
                if(!rem.empty())
                {
                    P temp = *rem.begin();
                    mini.insert(temp);
                    rem.erase(temp);
                    sum+=temp.first;
                }
            }
            else
            {
                rem.erase(remove);
            }
            i++;
            
        }
        return ans+nums[0];


    }
};