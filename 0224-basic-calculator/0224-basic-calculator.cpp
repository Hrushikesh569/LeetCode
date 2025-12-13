class Solution {
public:
    int calculate(string s) {
        stack<int>stack;
        long long  num = 0 ; 
        int result = 0 ; 
        int sign = 1;
        for(int i = 0 ; i < s.size() ;i++)
        {
            if(isdigit(s[i]))
            {
                num = num*10 + ((s[i]-'0'));
            }
            if(s[i]=='+')
            {
                result+=(num*sign);
                num = 0;
                sign = 1;
            }
            if(s[i]=='-')
            {
                result+=(num*sign);
                num = 0 ; 
                sign = -1;
            }
            if(s[i]=='(')
                {
                    stack.push(result);
                    stack.push(sign);
                    sign = 1;
                    result = 0 ; 
                    num = 0 ;
                }
            if(s[i]==')')
            {
                result += num*sign;
                int sin = stack.top() ; stack.pop();
                int val = stack.top();stack.pop();
                result *=sin;
                num = 0 ; 
                result+=val;
            }
        }
        result += (num*sign);
        return result;
    }
};