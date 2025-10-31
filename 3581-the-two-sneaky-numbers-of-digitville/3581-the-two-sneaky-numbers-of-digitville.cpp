class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int check[101];
        for(auto i : nums)
        {
            check[i]++;
        }
        vector<int>ans;
        for(int i = 0 ; i <= 100 ; i++) 
        if(check[i]>1) ans.push_back(i);
        return ans;
    }
};