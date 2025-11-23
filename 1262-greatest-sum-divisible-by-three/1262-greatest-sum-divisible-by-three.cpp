class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
      vector<vector<int>>v(n+1,vector<int>(3,-1e9));
      v[n][0] = 0;
      for(int i =n-1  ; i >=0  ; i--)
      {
        for(int j = 0 ; j < 3 ; j++)
        {
            int x = (nums[i]+j)%3;
            int take = nums[i]+v[i+1][x];
            int nott = v[i+1][j];
            v[i][j] = max(take,nott);
        }
      }
      return v[0][0];
    }
};