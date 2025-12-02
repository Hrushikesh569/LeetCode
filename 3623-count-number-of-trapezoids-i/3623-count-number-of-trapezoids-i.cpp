#define ll long long 
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<ll,ll>mp;
        for(auto i : points )
        {
            mp[i[1]]++;
        }
        ll ans = 0 ; 
        ll val = 0 ; 
        int m = 1e9+7;
        for(auto [x , y] : mp)
        {
            ll temp = (y*(y-1))/2;
            ans+=temp*val;
            val+=temp;
        }
        ans = ans%m;
        return ans;
    }
};