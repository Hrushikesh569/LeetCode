class Solution {
public:
    void f(vector<string> x, vector<int>& y, vector<int>& x1) {
        int t = stoi(x[1]);
        vector<string> v;
        stringstream ss(x[2]);
        string z;
        while (ss >> z) v.push_back(z);

        for (string s : v) {
            if (s == "ALL") {
                for (int i = 0; i < y.size(); i++) y[i]++;
            } 
            else if (s == "HERE") {
                for (int i = 0; i < y.size(); i++) {
                    if (x1[i] == 0 || x1[i] + 60 <= t) y[i]++;
                }
            } 
            else {
                y[stoi(s.substr(2))]++;
            }
        }
    }

    vector<int> countMentions(int n, vector<vector<string>>& e) {
        vector<int> y(n), x1(n);

        auto cmp = [](vector<string>& a, vector<string>& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 == t2) return a[0][1] > b[0][1];
            return t1 < t2;
        };

        sort(e.begin(), e.end(), cmp);

        for (vector<string> x : e) {
            if (x[0] == "MESSAGE") {
                f(x, y, x1);
            } else if (x[0] == "OFFLINE") {
                int t = stoi(x[1]);
                int id = stoi(x[2]);
                x1[id] = t;
            }
        }

        return y;
    }
};
