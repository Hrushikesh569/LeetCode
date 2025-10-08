class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int>ans;
        int m = potions.size();
        for(int i = 0 ; i < n ; i++)
        {
            long long  x = 1LL*ceil((double)success/(double)spells[i]);
            auto it = lower_bound(potions.begin(),potions.end(),x);
            int ind = it-potions.begin();
            if(ind>=m || ind<0)
            {
                ans.push_back(0);
            }
            else
            ans.push_back((m-ind));
        }
        return ans;
    }
};