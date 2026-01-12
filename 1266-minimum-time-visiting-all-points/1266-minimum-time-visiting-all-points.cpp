class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0 ; 
        int n = points.size();
        for(int i= 0 ; i < n - 1 ;i++)
        {
            int x = abs(points[i][0]-points[i+1][0]);
            int y = abs(points[i][1]-points[i+1][1]);
            ans+= max(x,y);
        }
        return ans; 
    }
};