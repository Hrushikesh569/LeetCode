class Solution {
public:
    int totalMoney(int n) {
        int ans = 0 ; 
        int cnt = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = i ; j < i+7 ; j++)
            {
                if(cnt==n) return ans;
                cnt++;
                ans+=j;
            }
        }
        return ans;
    }
};