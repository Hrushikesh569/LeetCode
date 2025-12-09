class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stack;
        for(auto i : s)
        {
            if(stack.empty() || stack.top()!=i) stack.push(i);
            else
            while(!stack.empty() && stack.top()==i)
            {
                stack.pop();
            }
        }
        string ans;
        while(!stack.empty()) 
        {
            ans+=stack.top();
            stack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};