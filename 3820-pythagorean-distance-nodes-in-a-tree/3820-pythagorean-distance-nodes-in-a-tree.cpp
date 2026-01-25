class Solution {
public:
    void dfs(vector<vector<int>>&adj,int x,vector<int>&v)
    {
        queue<int>q;
        q.push(x);
        v[x] = 0 ;  
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i : adj[node])
            {
                if(v[i]==-1)
                {
                    v[i] = v[node]+1;
                    q.push(i);
                }
            }
        }
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int> disx(n,-1),disy(n,-1),disz(n,-1);
        dfs(adj,x,disx);
        dfs(adj,y,disy);
        dfs(adj,z,disz);
        int cnt = 0 ;  
        for(int i = 0  ; i < n ;i++)
        {
            vector<long long>v = {disx[i],disy[i],disz[i]};
            sort(v.begin(),v.end());
            cnt+=((v[0]*v[0]+v[1]*v[1])==v[2]*v[2]);
        }
        return  cnt; 
    }
};