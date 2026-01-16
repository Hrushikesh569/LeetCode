class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& a, vector<int>& b) {
        unordered_set<long long > st;
        a.push_back(m);
        b.push_back(n);
        a.push_back(1);
        b.push_back(1);
        for(int i= 0 ; i< a.size();i++)
        {
            for(int j = i+1 ; j<a.size() ;j++)
            {
                int x = abs(a[i]-a[j]);
                st.insert(x);
            }
        }
       // for(auto i : st)cout<<i<<" ";
        long long maxi = -1 ;
        for(int i = 0 ; i < b.size(); i++)
        {
            for(int j = i+1 ; j < b.size() ;j++)
            {
                long long  x = abs(b[i]-b[j]);
                if(st.count(x))
                {
                    maxi = max(maxi,x);
                }
            }
        }
       // cout<<maxi<<"--"<<endl;
        if(maxi<0) return -1;
        return (maxi*maxi)%1000000007;
    }
};