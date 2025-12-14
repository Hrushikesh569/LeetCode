class Solution {
public:
    int numberOfWays(string s) {
        int n  = s.size();
        int m = 1e9+7;
        vector<int>v;
        for(int i= 0 ; i < n ;i++)
        {
            if(s[i]=='S') v.push_back(i);
        }
        n = v.size();
        if(n&1 || n==0) return 0;
        long long ans =1 ; 
        long long prev = v[1];
      //  for(auto i: v)cout<<i<<" ";
        for(int i = 2 ; i < n ; i+=2) 
        {
            long long  val = v[i] - prev;
            ans = (ans * 1LL * val)%m;
            prev = v[i+1];
        }
        return ans;
    }
};