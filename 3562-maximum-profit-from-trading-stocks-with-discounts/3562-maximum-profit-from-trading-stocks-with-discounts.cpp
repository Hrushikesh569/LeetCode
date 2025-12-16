#include <bits/stdc++.h>
using namespace std;

const int N = 161, N4 = N * 4;

int p[N][2];          // profit
vector<int> g[N];     // tree edges
int dp[N][2][2][N];   // node, bossBought, bought, budget
bitset<N4> v;         // visited

class Solution {
public:
    int n;

    void build(vector<vector<int>>& h) {
        for (int i = 0; i < n; i++) g[i].clear();
        for (auto &e : h) g[e[0] - 1].push_back(e[1] - 1);
    }

    void dfs(int u, bool bb, bool b, int B, const vector<int>& c) {
        int idx = (u << 2) | (bb << 1) | b;
        if (v[idx]) return;
        v[idx] = 1;

        int* dpU = dp[u][bb][b];
        fill(dpU, dpU + B + 1, INT_MIN);

        int cost = b ? (bb ? c[u]/2 : c[u]) : 0;
        if (cost <= B) dpU[cost] = b ? p[u][bb] : 0;

        int* cur = (int*)alloca(sizeof(int) * (B + 1));
        int* mrg = (int*)alloca(sizeof(int) * (B + 1));
        memcpy(cur, dpU, sizeof(int) * (B + 1));

        for (int x : g[u]) {
            dfs(x, b, 1, B, c);
            dfs(x, 0, 0, B, c);

            int* t = dp[x][b][1];
            int* s = dp[x][0][0];

            fill(mrg, mrg + B + 1, INT_MIN);

            for (int i = 0; i <= B; i++) if (cur[i] != INT_MIN) {
                for (int j = 0; i + j <= B; j++) {
                    int best = max(t[j], s[j]);
                    if (best != INT_MIN) mrg[i+j] = max(mrg[i+j], cur[i] + best);
                }
            }

            memcpy(cur, mrg, sizeof(int) * (B + 1));
        }

        memcpy(dpU, cur, sizeof(int) * (B + 1));
    }

    int maxProfit(int n_, vector<int>& c, vector<int>& f, vector<vector<int>>& h, int B) {
        n = n_;
        v.reset();

        for (int i = 0; i < n; i++) {
            p[i][0] = f[i] - c[i];
            p[i][1] = f[i] - c[i]/2;
        }

        build(h);

        dfs(0, 0, 0, B, c);
        dfs(0, 0, 1, B, c);

        int ans = 0;
        for (int i = 0; i <= B; i++) {
            ans = max(ans, dp[0][0][0][i]);
            ans = max(ans, dp[0][0][1][i]);
        }
        return ans;
    }
};
