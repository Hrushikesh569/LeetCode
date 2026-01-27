class Solution {
public:
    #define p pair<int,int>
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<p>>adj(n);
        for(int i = 0 ; i < edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]*2});
        }
        vector<int> ans(n,1e9);
       n--;
        ans[0] = 0;
        priority_queue<p,vector<p>,greater<p>>q;
        q.push({0,0});
        while(!q.empty())
        {
            int d = q.top().first;
            int node = q.top().second;
            q.pop();
            if(d>ans[node]) continue;
            for(auto &it : adj[node])
            {
                int niber = it.first;
                int wt = it.second;
                if(d+wt<ans[niber])
                {
                    ans[niber] = d+wt;
                    q.push({d+wt,niber});
                }
            }
        }
        return (ans[n]==1e9?-1:ans[n]);
    }
};