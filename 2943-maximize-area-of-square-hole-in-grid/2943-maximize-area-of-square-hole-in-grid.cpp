class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int v = 1 , h = 1 ; 
        int cur = 1 ;
        for(int i = 0 ; i < a.size() - 1 ; i++)
        {
            if(a[i]==a[i+1]-1) cur++;
            else cur = 1 ; 
            v = max(v,cur);
        }
        cur =1 ;
        for(int i = 0 ; i < b.size() - 1 ; i++)
        {
            if(b[i]==b[i+1]-1) cur++;
            else cur = 1 ; 
            h = max(h,cur);
        }
        v = min(v,h);
        v++;
        return v*v;
    }
};