class Solution {
public:
    int minLengthAfterRemovals(string s) { 
        int a[2] = {0};
        for(int i = 0 ; i < s.size(); i++)
        {
            a[s[i]-'a']++;
        }  
        int mini = min(a[0],a[1]);
        return s.size()-mini*2;
    }
};
