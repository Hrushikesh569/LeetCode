class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n , vector<int>(m));
        for(int i = 0 ; i <  n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]>1)
                {
                    q.push(make_pair(make_pair(i,j),0));
                    vis[i][j] = 1 ; 
                }
            }
        }
        int ans = 0; 
        vector<int>x = {-1,1,0,0};
        vector<int>y = {0,0,-1,1};
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int xx = 0 ; xx < 4 ; xx++)
            {
                int r = i + x[xx];
                int c = j + y[xx];
                if(r>=0 and c>=0 and r<n and c<m and !vis[r][c] and grid[r][c]>0)
                {
                    vis[r][c] = 1;
                    q.push({{r,c},time+1});
                    ans  = max(ans , time+1);
                }
            //    cout<<ans<<endl;
                
            }
          }
          for(int i = 0; i < n; i++)
            {
                for(int j = 0 ; j < m ; j++)
                {
                    if(vis[i][j]==0 and grid[i][j]==1) return -1;
                }
            }
         return ans; 
    }
};