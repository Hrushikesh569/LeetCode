class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>v(n,vector<int>(n,0));
        for(auto ii:queries)
        {
          int   r1 = ii[0];
           int  r2 = ii[2];
            int c1 = ii[1];
            int c2 = ii[3];
            for(int i = r1 ; i <=r2 ; i++)
            {
                for(int j = c1 ; j<=c2 ;j++)
                {
                    v[i][j]++;
                }
            }
        }
        return v;
    }
};