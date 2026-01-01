class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int val = 0  ;
        int n = digits.size();
        vector<int>ans;
        int rem = 0 ; 
        digits[n-1]++;
        for(int i = n-1 ;i>=0 ;i--)
        {
            int x = (digits[i]+rem)%10;
            rem = (digits[i]+rem)/10;
            ans.push_back(x);
        }
        if(rem)
        ans.push_back(rem);
        reverse(ans.begin(),ans.end());
        return ans;
    }

};