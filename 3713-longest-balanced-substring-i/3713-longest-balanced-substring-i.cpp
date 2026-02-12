class Solution {
public:
    int longestBalanced(string s) {
        int maxi = 1;
        int n = s.size();
        for(int i = 0 ; i < n - 1; i++)
            {
                unordered_map<char,int>mp;
                mp[s[i]]++;
                for(int j = i+1 ; j < n ; j++)
                    {
                        mp[s[j]]++;
                        int flag = 1 ;
                        for(auto [key , val]: mp)
                            {
                                if(val!=mp[s[i]] )
                                {
                                    flag = 0;
                                    break;
                                }
                            }
                        if(flag)
                        {
                            maxi = max(maxi , j-i+1);
                        }
                    }
            }
        return maxi;
    }
};