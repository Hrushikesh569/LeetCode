class Solution {
public:
    int triangularSum(vector<int>& v) {
        int n = v.size();
        for(int i = 0 ; i < n-1 ; i++)
        {
            for(int j = 0 ; j < n-i-1 ; j++)
            {
                v[j] = (v[j]+v[j+1])%10;
            }
        }
        return v[0];
    }
};