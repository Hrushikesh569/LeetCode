class Solution {
public:
    int mostBooked(int a, vector<vector<int>>& b) {
        sort(b.begin(), b.end());

        vector<int> c(a);
        vector<long long> d(a);

        int e = 0;

        while (e < b.size()) {
            int f = b[e][0];
            int g = b[e][1];
            long long h = g - f;

            int i = -1;
            long long j = LLONG_MAX;
            int k = -1;

            for (int l = 0; l < a; l++) {
                if (d[l] < j) {
                    j = d[l];
                    k = l;
                }
                if (d[l] <= f) {
                    i = l;
                    break;
                }
            }

            if (i != -1) {
                d[i] = g;
                c[i]++;
            } else {
                d[k] += h;
                c[k]++;
            }

            e++;
        }

        int m = 0, n = 0;
        for (int o = 0; o < a; o++) {
            if (c[o] > m) {
                m = c[o];
                n = o;
            }
        }

        return n;
    }
};
