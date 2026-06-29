class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        if(!nums.size()) return 0;
        int maxi = 1 , n = nums.size();
        for(int i =0; i < n ; i++)
        {
            st.insert(nums[i]);
        }
        for(auto i :st)
        {
            if(!st.count(i-1))
            {
                int x = i ; 
                int cnt =1 ; 
                while(st.count(x+1))
                {
                    cnt++;
                    x++;
                }
                maxi = max(maxi , cnt);
            }
        }
        return maxi;
    }
};