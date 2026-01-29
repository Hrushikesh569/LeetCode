class Solution {
public:
    int minCost(vector<vector<int>>& a, int K) {
        int R = a.size();
        int C = a[0].size();
        const int INF = 1e9;
        const int LIM = 10000;

        vector<vector<pair<int,int>>> pos(LIM + 1);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pos[a[i][j]].push_back({i, j});
            }
        }

        vector<vector<vector<int>>> dp(
            K + 1, vector<vector<int>>(R, vector<int>(C, INF))
        );

        dp[0][0][0] = 0;

        for (int t = 0; t <= K; t++) {
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (dp[t][i][j] != INF) {
                        pq.push({dp[t][i][j], i * C + j});
                    }
                }
            }

            while (!pq.empty()) {
                auto [cd, x] = pq.top();
                pq.pop();

                int r = x / C;
                int c = x % C;
                if (cd > dp[t][r][c]) continue;

                if (r + 1 < R && dp[t][r + 1][c] > cd + a[r + 1][c]) {
                    dp[t][r + 1][c] = cd + a[r + 1][c];
                    pq.push({dp[t][r + 1][c], (r + 1) * C + c});
                }

                if (c + 1 < C && dp[t][r][c + 1] > cd + a[r][c + 1]) {
                    dp[t][r][c + 1] = cd + a[r][c + 1];
                    pq.push({dp[t][r][c + 1], r * C + (c + 1)});
                }
            }

            if (t < K) {
                vector<int> best(LIM + 1, INF);
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        best[a[i][j]] = min(best[a[i][j]], dp[t][i][j]);
                    }
                }

                vector<int> suf(LIM + 2, INF);
                for (int v = LIM; v >= 0; v--) {
                    suf[v] = min(suf[v + 1], best[v]);
                }

                for (int v = 0; v <= LIM; v++) {
                    if (suf[v] == INF) continue;
                    for (auto &p : pos[v]) {
                        dp[t + 1][p.first][p.second] =
                            min(dp[t + 1][p.first][p.second], suf[v]);
                    }
                }
            }
        }

        int res = INF;
        for (int t = 0; t <= K; t++) {
            res = min(res, dp[t][R - 1][C - 1]);
        }

        return res >= INF ? -1 : res;
    }
};