class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> rowPrefix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            rowPrefix[i][0] = mat[i][0];
            for (int j = 1; j < m; j++) {
                rowPrefix[i][j] = rowPrefix[i][j - 1] + mat[i][j];
            }
        }

        vector<vector<int>> colPrefix(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            colPrefix[0][j] = mat[0][j];
            for (int i = 1; i < n; i++) {
                colPrefix[i][j] = colPrefix[i - 1][j] + mat[i][j];
            }
        }

        for (int len = min(n, m); len >= 2; len--) {

            for (int r = 0; r + len - 1 < n; r++) {
                for (int c = 0; c + len - 1 < m; c++) {

                    int baseSum = rowPrefix[r][c + len - 1] - (c > 0 ? rowPrefix[r][c - 1] : 0);

                    bool valid = true;

                    for (int x = r + 1; x < r + len; x++) {
                        int sum = rowPrefix[x][c + len - 1] - (c > 0 ? rowPrefix[x][c - 1] : 0);
                        if (sum != baseSum) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid)
                        continue; // dont go next broo skip it ////////
                    for (int y = c; y < c + len; y++) {
                        int sum = colPrefix[r + len - 1][y] - (r > 0 ? colPrefix[r - 1][y] : 0);
                        if (sum != baseSum) {
                            valid = false;
                            break;
                        }
                    }
                    if (!valid)
                        continue;

                 int d1 = 0, d2 = 0;
                     for (int k = 0; k < len; k++) {
                        d1 += mat[r + k][c + k];
                        d2 += mat[r + k][c + len - 1 - k];
                }
                    if (d1 == baseSum && d2 == baseSum) {
                        return len;
                    }
                }
            }
        }

        return 1;
    }
};
