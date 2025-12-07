class Solution {
public:
    int countOdds(int low, int high) {
        if((high - low + 1)%2==0) return (high - low + 1)/2;
        int ans = (high%2==0 && low%2==0) ? 0 : 1;
        ans+=(high-low)/2;
        return ans;
    }
};