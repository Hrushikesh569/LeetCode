class Solution {
public:
    bool wordPattern(string p, string s) {
        int cnt = 0;
        int n = s.size();
        vector<string>v;
        int i = 0 , j = 0 ;
        while(j<n)
        {
            if(s[j]==' ')
            {
                //cout<<i<<"----"<<j<<endl;
                string x = s.substr(i,j-i);
                v.push_back(x);
                i = j+1;
                j++;
            }
            j++;
        }
       v.push_back(s.substr(i));
       // for(auto i : v) cout<<i<<" ";
       if(v.size()!=p.size()) return false;
       unordered_map<char, string>mp;
        unordered_set<char>check1 ;
        unordered_set<string>check2;
       for(int i =0 ; i < p.size() ; i++)
       {
        check1.insert(p[i]);
        check2.insert(v[i]);
        if(mp.count(p[i]))
        {
            if(v[i]!=mp[p[i]]) return  0;
            
        }
        mp[p[i]] = v[i];
       }
      if(check1.size()!=check2.size()) return 0;
       
        return 1;


        
    }
};