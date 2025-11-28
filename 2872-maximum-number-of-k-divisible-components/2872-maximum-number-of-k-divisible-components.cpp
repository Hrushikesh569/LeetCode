class Solution {
public:
    int cnt;
    int  dfs(int cur , int p , unordered_map<int,vector<int>>&adj,vector<int>&v , int k)
    {
        int sum =v[cur]; 
        for(auto i : adj[cur])
        {
            if(i!=p)
            {
                sum+=dfs(i , cur,adj,v,k);
                sum %=k;

            }
        }
        sum%=k;
        if(sum==0) cnt++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        cnt = 0 ; 
        unordered_map<int,vector<int>>adj;
        for(auto & i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0 , -1 , adj , values, k);
        return cnt;
    }
};