class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int>sorted(n,0);
        int del = 0;
        for(int col = 0 ; col<m;col++)
        {
            bool isdel = 0;
            for(int row = 0 ; row < n-1 ; row++)
            {
                if(!sorted[row] && strs[row][col]>strs[row+1][col]){
                    del++;
                    isdel = 1;
                    break;
                }
            }
            if(isdel) continue;
            for(int i = 0 ; i < n -1 ; i++)
            {
                sorted[i] |= (strs[i][col]<strs[i+1][col]);
            }
        }
        return del;
    }
};