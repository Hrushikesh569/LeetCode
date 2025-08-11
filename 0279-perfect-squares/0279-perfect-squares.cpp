class Solution {
public:
unordered_map<int,int>mp;

    int dfs(vector<int> &v , int target )
    {
        if(target==0)
        {
            return 0;
        }
        if(target<0) return INT_MAX;
        if(mp.count(target))
        {
            return mp[target];
        }
       int mini = INT_MAX;
        for(int i : v)
        {
             
            int ans = dfs(v,target-i );
            if(ans!=INT_MAX)
            {
                mini = min(mini , ans+1);
            }
        }
        return mp[target] = mini;
    }
    int numSquares(int n) {
       int x = 1;
       vector<int>v;
       for(int i = 1 ; i*i<= n ;i++)
       {
            v.push_back(i*i);
       }
       
     
       for(auto i : mp) cout<<i.first<<" "<<i.second<<endl;
        return dfs(v,n);;
    }
};