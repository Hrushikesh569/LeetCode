class Solution {
public:
    // int dfs(int i ,int j , vector<vector<int>>&nums)
    // {
    //     if(i == nums.size()-1)
    //     {
    //         return nums[i][j];
    //     }
    //     int c = 1e9 , next = 1e9;
        
    //     next =  dfs(i+1 , j+1,  nums);
    //     c = dfs(i+1 , j,nums);
        
    //     return min(next , c)+nums[i][j] ; 
    // }
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>cur(n),prev(n);
        for(int i = n - 1;  i >= 0 ; i--)
        {
            prev[i] = nums[n-1][i];
        }
        for(int i = n - 2 ; i>= 0 ; i--)
        {
            for(int j = i ; j>=0 ; j--)
            {
                cur[j] = min(prev[j+1],prev[j])+nums[i][j];
            }
            prev = cur;
        }
        // for(auto i : dp)
        // {
        //     for(auto j: i)cout<<j<<" ";
        //     cout<<endl;
        // }
        return prev[0];
    }
};