class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        for(int & i : nums)
        {
            if(i>=0)
            i = i%value;
            else
            {
                int x  = (abs(i)%value);
                i = (value-x)%value;
            }   
            mp[i]++;   
        }
        for(auto [key,val]:mp)
        {
           
            int x = val;
            int z = key;
            x--;
            st.insert(key);
            while(x>0)
            {
                z +=value;
                st.insert(z);
                x--;
            }
             
        }
       //  for(auto i: st)cout<<i<<" ";
        int flag = 0;
        while(st.count(flag++));
        sort(nums.begin(),nums.end());
        // for(auto i : nums)cout<<i<<" ";

        return flag-1;
    }
};