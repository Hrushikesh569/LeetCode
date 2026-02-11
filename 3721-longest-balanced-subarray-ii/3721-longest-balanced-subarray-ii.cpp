class Solution {
public:
    vector<int> mn, mx, lz;
    int sz;

    void push(int idx, int l, int r) {
        if (lz[idx] != 0) {
            mn[idx] += lz[idx];
            mx[idx] += lz[idx];

            if (l != r) {
                lz[2*idx+1] += lz[idx];
                lz[2*idx+2] += lz[idx];
            }
            lz[idx] = 0;
        }
    }

    void update(int ql, int qr, int idx, int l, int r, int v) {
        push(idx, l, r);

        if (l > qr || r < ql) return;

        if (l >= ql && r <= qr) {
            lz[idx] += v;
            push(idx, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(ql, qr, 2*idx+1, l, mid, v);
        update(ql, qr, 2*idx+2, mid+1, r, v);

        mn[idx] = min(mn[2*idx+1], mn[2*idx+2]);
        mx[idx] = max(mx[2*idx+1], mx[2*idx+2]);
    }

    int queryZero(int idx, int l, int r) {
        push(idx, l, r);

        if (mn[idx] > 0 || mx[idx] < 0) return -1;

        if (l == r) return l;

        int mid = l + (r - l) / 2;
        int left = queryZero(2*idx+1, l, mid);
        if (left != -1) return left;

        return queryZero(2*idx+2, mid+1, r);
    }

    int longestBalanced(vector<int>& arr) {
        sz = arr.size();
        mn.assign(4*sz, 0);
        mx.assign(4*sz, 0);
        lz.assign(4*sz, 0);

        int ans = 0;
        unordered_map<int,int> last;

        for (int r = 0; r < sz; r++) {
            int val = (arr[r] % 2 == 0) ? 1 : -1;

            int prev = last.count(arr[r]) ? last[arr[r]] : -1;

            if (prev != -1) {
                update(0, prev, 0, 0, sz-1, -val);
            }

            update(0, r, 0, 0, sz-1, val);

            int l = queryZero(0, 0, sz-1);
            if (l != -1)
                ans = max(ans, r - l + 1);

            last[arr[r]] = r;
        }

        return ans;
    }
};
