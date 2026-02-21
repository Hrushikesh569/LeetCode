class Solution {
public:
    unordered_set<int>st = {2,3,5,7,11,13,17,19,21,23,27,31};
    int countPrimeSetBits(int left, int right) {
        int ans = 0; 
        for(int i = left; i<=right;i++)
        {
            int cnt = 0 ; 
            for(int bit = 0 ; bit<32;bit++)
            {
                if((i>>bit)&1)
                {
                    cnt++;
                }
            }
            if(st.count(cnt)) ans++;
        }
        return ans;
    }
};