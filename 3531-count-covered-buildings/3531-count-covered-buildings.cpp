class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& v) {
        unordered_map<int, pair<int,int>> a, b;
        int m = v.size();

        for (int i = 0; i < m; i++) {
            int x = v[i][0];
            int y = v[i][1];

            if (!a.count(x)) a[x] = {INT_MAX, INT_MIN};
            if (!b.count(y)) b[y] = {INT_MAX, INT_MIN};

            a[x].first = min(a[x].first, y);
            a[x].second = max(a[x].second, y);

            b[y].first = min(b[y].first, x);
            b[y].second = max(b[y].second, x);
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            int x = v[i][0];
            int y = v[i][1];

            auto &p = a[x];
            auto &q = b[y];

            if (p.first < y && y < p.second &&
                q.first < x && x < q.second)
                ans++;
        }

        return ans;
    }
};
