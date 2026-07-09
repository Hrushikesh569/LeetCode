class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ; 
        int cnt = 0;  
        for(auto i : s)
        {
            if(i=='(')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt>1 or (cnt==1 and i==')'))
            {
                ans+=i;
            }
        }
        return ans; 
    }
};