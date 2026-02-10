class Solution {
public:
    #define ll long long 
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0 ; i <n ; i++)
        {
            unordered_set<int>st;
            int even = 0,  odd = 0 ; 
            for(int j = i ; j < n ;j++)
            {
                even+=(nums[j]%2==0 && !st.count(nums[j]));
                odd+=(nums[j]%2!=0 && !st.count(nums[j]));
                st.insert(nums[j]);
                //cout<<even<<"---"<<odd<<endl;
                if(even==odd)
                {
                 //   cout<<i<< " "<<j<<endl;
                    maxi = max(maxi , j - i +1);
                }
            }
        }
        return maxi;
    }
};