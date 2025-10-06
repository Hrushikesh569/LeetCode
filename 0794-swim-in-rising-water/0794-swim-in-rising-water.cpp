#define p pair<int,pair<int,int>>
class Solution {
public:
    bool isvalid(int x , int y, int n)
    {
        return (x>=0 && y>=0 && x<n && y<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<p,vector<p>,greater<p>>q;
        int maxi = grid[0][0];
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push(make_pair(grid[0][0],make_pair(0,0)));
        int level = grid[0][0];
        vector<int>dir= {-1,0,1,0,-1};
        vis[0][0]=1;
        while(!q.empty())
        {
            auto val = q.top();
            q.pop();
            int x = val.first;
            int r  = val.second.first,c = val.second.second;
            cout<<c<<endl;
            int rr , cc;
            int vall = 10000000;
            maxi = max(maxi , x);
            if(r==c&&c==n-1) return maxi;
            for(int i = 0 ; i < 4 ; i++)
            {
                int  row = r+dir[i];
                int col =   c+dir[i+1];
                if(isvalid(row,col,n) && !vis[row][col])
                {
                     q.push(make_pair(grid[row][col],make_pair(row,col)));
                  
                     vis[row][col]  = 1;
                     
                }
            }
            
        }
    return maxi;
    }
};