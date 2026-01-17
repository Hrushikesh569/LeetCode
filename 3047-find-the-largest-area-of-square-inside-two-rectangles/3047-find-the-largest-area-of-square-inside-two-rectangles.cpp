class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        long long maxi = 0 ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                int toprx = max(a[i][0],a[j][0]);
                int botlx = min(b[i][0],b[j][0]);
                int sidex = botlx-toprx;
                int topry = max(a[i][1],a[j][1]);
                int botly = min(b[i][1],b[j][1]);
                int sidey = botly-topry;
                long long side  = min(sidex,sidey);
                maxi = max(side,maxi);
            }
        }
        return maxi*maxi;
    }
};