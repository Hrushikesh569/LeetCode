class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>mp1,mp2;
        int cnt1=0,cnt2=0;
        for(auto i:s)
        {
            if(i=='a' || i=='u' || i=='o' || i=='i' || i=='e' )
            {
                mp1[i]++;
                cnt1 = max(cnt1,mp1[i]);
            }
            else
            {
                mp2[i]++;
                 cnt2 = max(cnt2,mp2[i]);
            }
        }
        return (cnt1+cnt2);
    }
};