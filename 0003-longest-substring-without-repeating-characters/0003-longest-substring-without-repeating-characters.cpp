class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char>st;
       int i = 0 ; 
       int j = 0 ; 
       int ans = 0 ; 
       while(j<s.size())
       {
            if(!st.count(s[j]))
            {
                st.insert(s[j]);
                j++;
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
            ans = max((int)st.size(),ans);
       }
       return ans ;
    }
};