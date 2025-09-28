class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>v;
        string x = to_string(n);
        reverse(x.begin(),x.end());
        long long val = 1;
        for(auto i : x)
        {
            if(i!='0')
            {
                v.push_back(val*(i-'0'));
            }
            val*=10;
        }
        sort(v.rbegin(),v.rend());
        return v;
    }
};