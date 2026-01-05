class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0 ; 
        int n = matrix.size();
        int small = 1e7; 
        int cnt = 0 ;
        int cnt2 = 0;
        for(int i = 0 ;i < n ;i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(matrix[i][j]<0)
                {
                  //  cout<<small<< " ";
                    cnt++;
                }
                if(matrix[i][j])
                {
                    small = min(small , abs(matrix[i][j]));
                }
                cnt2+=(matrix[i][j]==0);
                ans+=(abs(matrix[i][j]));
            }
        }
        if(cnt&1 && cnt2==0)
        {
            ans-=(small*2);
        }
        return ans;
    }
};