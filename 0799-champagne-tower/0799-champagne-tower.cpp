class Solution {
public:
    double champagneTower(int poured, int row, int col) {
        poured%=1000000007;
        vector<vector<double>>v(101,vector<double>(101,0));
        v[0][0] = poured;
        for(int i = 0 ; i <=row ;i++)
        {
            for(int j = 0  ; j<=i;j++)
            {
                double x = (v[i][j]-1)/2.0;
                if(x>0)
                {
                    v[i+1][j] +=x;
                    v[i+1][j+1]+=x;
                }
            }
        }
        // for(auto i : v)
        // {
        //     for(auto &j : i)
        //     {
        //         if(j>1) j = 1;
        //         if(j)
        //         {
        //             cout<<j<<" ";
        //         }
        //     }
        //     cout<<endl;
        // }
        return min(1.0,v[row][col]) ;
    }
};