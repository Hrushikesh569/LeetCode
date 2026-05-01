class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi = 0 ; 
        int n = s.size();
        for(int i= 0 ; i < n; i++)
        {
            vector<int>v(26);
            for(int j = i ; j < n ; j++)
            {
                v[s[j]-'a']++;
                int flag =  0 ; 
                for(int i =0 ; i < 26 ; i++)
                {
                    if(v[i]>0 and v[i]<k) 
                    {
                        flag = 1;
                        break;
                    }
                }
                if(!flag)
                {
                    maxi = max(maxi , j - i + 1);
                }
            }
        }
        return maxi;
    }
};