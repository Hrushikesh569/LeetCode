class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string> bl = {"electronics", "grocery", "pharmacy", "restaurant"};
        unordered_set<char>an;
        char qq = 'A';
        for(char i = 'a';i<='z';i++)
            {
                an.insert(i);
                an.insert(qq++);
            }
        for(int i = 0 ; i<10;i++)
            {
                an.insert('0'+i);
            }
        an.insert('_');
        int n = code.size();
        bool checking = true;
        vector<int>check(n);
        for(int i = 0 ; i<n;i++)
            {
                if(isActive[i])
                {
                    check[i] = 1;
                    checking = true;
                for(int j = 0 ; j<code[i].size();j++)
                    {
                        if(!an.count(code[i][j]))
                        {
                            checking = false;
                            break;
                        }
                    }
                if(checking) check[i] = 1;
                else check[i] = 0;
                if(!bl.count(businessLine[i]))
                {
                    checking = false;
                }
                if(!check[i] || !checking)
                {
                    check[i] = 0;
                }
                }
            }
        vector<string>ans;
        map<string,multiset<string>>mp;
        for(int i =0 ; i < n ; i++)
            {
                if(check[i])
                {
                    mp[businessLine[i]].insert(code[i]);
                }
            }
        vector<string>vv =   {"electronics", "grocery", "pharmacy", "restaurant"};
        for(auto i : vv)
            {
                
                for(auto j : mp[i])
                    {
                        if(j.size()>0)
                        ans.push_back(j);
                    }
            }
        return ans;
    }
};