class Solution {
private:
    bool check(int rows, int cols, vector<vector<int>>& pos, int limit) {
        vector<vector<int>> mat(rows, vector<int>(cols, 0));

        for (int i = 0; i < limit; i++) {
            int x = pos[i][0] - 1;
            int y = pos[i][1] - 1;
            mat[x][y] = 1;
        }

        queue<pair<int,int>> qu;

        for (int j = 0; j < cols; j++) {
            if (mat[0][j] == 0) {
                qu.push({0, j});
                mat[0][j] = 1;
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!qu.empty()) {
            auto cur = qu.front();
            qu.pop();
            int r = cur.first;
            int c = cur.second;

            if (r == rows - 1) return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] == 0) {
                    mat[nr][nc] = 1;
                    qu.push({nr, nc});
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int r, int c, vector<vector<int>>& pos) {
        int low = 1;
        int high = pos.size();
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
                if (check(r, c, pos, mid)) {
                 res = mid;
            low = mid + 1;
            }
             else {
                high = mid - 1;
            }
        }
        return res;
    }
};
