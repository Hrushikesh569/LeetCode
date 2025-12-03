class Solution {
public:
    int countTrapezoids(vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<float, vector<float>>mp1;
        unordered_map<int, vector<float>> mp2;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = p[i][0], y1 = p[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = p[j][0], y2 = p[j][1];
                int dx = x1 - x2, dy = y1 - y2;
                float m, c;
                if (x1 == x2) {
                    m = 1e9 + 7;
                    c = x1;
                } else {
                    m = (float)(y2 - y1) / (x2 - x1);
                    c = (float)(y1 * dx - x1 * dy) / dx;
                }
                int key = (x1 + x2) *10000 + (y1 + y2);
                mp1[m].push_back(c);
                mp2[key].push_back(m);
            }
        }
        for (auto& it : mp1) {
            auto& v = it.second;
            if (v.size() <= 1) continue;
            map<float, int> f;
            for (float x : v) f[x]++;
            int pref = 0;
            for (auto& t : f) {
                ans += t.second * pref;
                pref += t.second;
            }
        }
        for (auto & it : mp2) {
            auto& v = it.second;
            if (v.size() <= 1)
             continue;
            map<float, int> f;
            for (float x : v) f[x]++;
            int pref = 0;
            for (auto& t : f) {
                ans -= pref * t.second;
                pref += t.second;
            }
        }
        return ans;
    }
};
