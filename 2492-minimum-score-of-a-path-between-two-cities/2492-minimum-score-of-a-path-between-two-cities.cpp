class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = 1e9; 
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i: roads)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>v(n+1);
        v[1] = 1;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            for(auto [niber,wt]: adj[node])
            {
                ans = min(ans , wt);
                if(!v[niber])
                {
                    v[niber] = 1  ; 
                    q.push(niber);
                }
            }
        }
        return ans;
    }
};