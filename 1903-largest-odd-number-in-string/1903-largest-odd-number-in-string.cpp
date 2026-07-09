class Solution {
public:
    string largestOddNumber(string num) {
        while(!num.empty() and (num[num.size()-1]-'0')%2==0)num.pop_back();
        return num;
    }
};