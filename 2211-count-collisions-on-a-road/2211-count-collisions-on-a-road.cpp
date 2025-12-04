class Solution {
public:
    int countCollisions(string s) {
        int ans = 0;  
        int n  = s.size();
        int i = 0 , j = n-1;
        while(i<n && s[i]=='L')i++;
        while(j>=0 && s[j]=='R')j--;
        cout<<i<<" "<<j;
        for(int ind = i ; ind <= j ;ind++)
        {
            ans+=(s[ind]!='S');
        }
        return ans;
    }
};