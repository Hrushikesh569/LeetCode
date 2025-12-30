class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0; 

        for(int i = 1; i < row - 1; i++) {
            for(int j = 1; j < col - 1; j++) {
                if (grid[i][j] != 5) continue;

                int top1 = grid[i-1][j-1], top2 = grid[i-1][j], top3 = grid[i-1][j+1];
                int side1 = grid[i][j-1],  side2 = grid[i][j],  side3 = grid[i][j+1];
                int bot1 = grid[i+1][j-1], bot2 = grid[i+1][j], bot3 = grid[i+1][j+1];

                 vector<int> vals = {top1, top2, top3, side1, side2, side3, bot1, bot2, bot3};
                vector<int> freq(16, 0);
                bool valid = true;
                for(int x : vals) {
                    if(x < 1 || x > 9 || ++freq[x] > 1) {
                        valid = false;
                        break;
                    }
                }
                if(!valid) continue;

                if(top1 + top2 + top3 == 15 &&
                   side1 + side2 + side3 == 15 &&
                   bot1 + bot2 + bot3 == 15 &&
                    top1 + side1 + bot1 == 15 &&
                 top2 + side2 + bot2 == 15 &&
                   top3 + side3 + bot3 == 15 &&
                 top1 + side2 + bot3 == 15 &&
                   top3 + side2 + bot1 == 15) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};