class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st2;
         for(int i = 0 ;i < s.size(); i++)
        {
            string ss = s.substr(i,k);
            st2.insert(ss);
        }
        for(int i = 0; i<(1<<k);i++)
        {
            string ss;
            for(int j = k - 1 ;j>=0 ; j--)
            {
                ss+=(((i>>j)&1)+'0');
            }
            if(!(st2.count(ss))) return 0;
        } 
        return 0==0;
    }
};