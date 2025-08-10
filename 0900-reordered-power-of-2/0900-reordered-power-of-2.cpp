class Solution {
public:
    vector<string>ans;
    void dfs(string &v , string &s,vector<bool>&used)
    {
        if(s.size()==v.size())
        {
             int x = (s[v.size()-1])-'0';
            if(s[0]!='0' && x%2==0 && x!=1)
            ans.push_back(s);
        }
        for(int i = 0 ; i < v.size() ;i++)
        {
            if(used[i]) continue;
            if(i>0 && v[i]==v[i-1] && !used[i-1])
            continue;
            s.push_back(v[i]);
            used[i] = true;
            dfs(v,s,used);
            s.pop_back();
            used[i] = 0;
        }
    }
    bool reorderedPowerOf2(int n) {
        if(n==1) return 1;
        string s="";
        ans.clear();
        string v = to_string(n);
        vector<bool>used(v.size(),false);
        dfs(v,s,used);
        
        for(auto i : ans) 
        {
           // cout<<i<<" ";
            long long x = stoll(i);
            if(x>INT_MAX)
            continue;
            int xx = 0;
            while(x>0)
            {
                if(xx>1) break;
                if(x&1)
                {
                    xx++;
                }
                x>>=1;
            }
            if(xx==1) return true;
        }
        return 0;
    }
};