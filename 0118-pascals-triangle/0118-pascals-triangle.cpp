class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i = 1; i < numRows ;i++)
        {
            int n = ans[i-1].size();
            
            vector<int>temp;
            temp.push_back(ans[i-1][0]);
            for(int x = 1 ; x < n  ; x++)
            {
                temp.push_back((ans[i-1][x-1]+ans[i-1][x]));
            }
            temp.push_back(ans[i-1][n-1]);
            ans.push_back(temp);
        }
        return ans ; 
    }
};