class Solution {
public:
    long long maxProfit(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        int h = k / 2;

        long long ans = 0;
        vector<long long> p(n);

        for (int i = 0; i < n; i++) {
            p[i] = 1LL * b[i] * a[i];
            ans += p[i];
        }

        long long x = 0, y = 0, mx = 0;
        int i = 0, j = 0;

        while (j < n) {
            x += p[j];

            if (j - i + 1 > h) {
                y += a[j];
            }

            if (j - i + 1 > k) {
                x -= p[i];
                y -= a[i + h];
                i++;
            }

            if (j - i + 1 == k) {
                mx = max(mx, y - x);
            }

            j++;
        }

        return ans + mx;
    }
};
