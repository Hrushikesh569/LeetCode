
#define p pair<int,pair<int,int>>
class Solution {
public:
    bool isvalid(int x , int y , int n , int m )
    {
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if(n<3 or m<3) return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<p,vector<p>,greater<p>>minheap;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(i==0 || i== n-1 || j == 0 || j == m-1)
                {
                    vis[i][j] = 1;
                    minheap.push(make_pair(heightMap[i][j],make_pair(i,j)));
                }
            }
        }
        int level = 0 , total = 0;
        vector<int>dir = {-1 , 0 , 1 , 0 , -1};
        while(!minheap.empty())
        {
            p curr = minheap.top();
            minheap.pop();
            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level,height);
            for(int i = 0 ; i < 4 ; i++)
            {
                int row = x+dir[i];
                int col = y+dir[i+1];
                if(isvalid(row,col,n,m) and !vis[row][col])
                {
                    vis[row][col] = 1;
                    minheap.push(make_pair(heightMap[row][col],make_pair(row,col)));
                    if(heightMap[row][col]<level)
                    {
                        total+=(level-heightMap[row][col]);
                    }
                }
            }
        }
        return total;
        
    }
};