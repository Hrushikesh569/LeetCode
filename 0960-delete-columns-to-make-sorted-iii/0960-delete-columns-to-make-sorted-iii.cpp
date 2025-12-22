class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int b = a.size();
        int c = a[0].length();

        vector<int> d(c, 1);
        int e = 1;

        for (int f = 0; f < c; ++f) {
            for (int g = 0; g < f; ++g) {

                bool h = true;

                for (int i = 0; i < b; ++i) {
                    if (a[i][g] > a[i][f]) {
                        h = false;
                    break;
                    }
                }
                if (h) {
                    d[f] = max(d[f], d[g] + 1);
                }
            }
            e = max(e, d[f]);
        }

        return c - e;
    }
};
