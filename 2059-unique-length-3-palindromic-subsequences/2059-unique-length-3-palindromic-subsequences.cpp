class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>v(26,{-1,-1});
        int n = s.size();
        int ans = 0 ; 
        for(int i = 0 ; i < n ;i++)
        {
            int x = s[i]-'a';
            if(v[x].first==-1) v[x].first = i;
            v[x].second = i;
        }
        for(auto [start , end]: v)
        {
            unordered_set<char>ud;
            if(start==end && start==-1) continue;
            for(int i = start+1 ; i <= end-1 ;i++)
            {
                ud.insert(s[i]);
            }
            ans+=ud.size();
        }
        return ans;
    }
};