class Solution {
public:
    int M = 1e9+7;
    vector<int> getL(vector<int>&v , int n)
    {
        stack<int>st;
        vector<int>ans(n);
        for(int i = 0; i < n ; i++)
        {
            if(st.empty()) ans[i] = -1;
            else 
            {
                while(!st.empty() && v[i]<v[st.top()]) st.pop();
                ans[i] = st.empty()?-1 : st.top();
                
            }
            st.push(i);
        }
        return ans;
    }
     vector<int> getR(vector<int>&v , int n)
    {
        stack<int>st;
        vector<int>ans(n);
        for(int i = n -1 ; i >= 0  ; i--)
        {
            if(st.empty()) ans[i] = n;
            else 
            {
                while(!st.empty() && v[i]<=v[st.top()]) st.pop();
                ans[i] = st.empty()?n : st.top();
                
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>ls = getL(arr , n);
        vector<int>rs = getR(arr , n);

        long long sum = 0 ; 
        for(int i  = 0 ;i < n ; i++)
        {
            long long left = i - ls[i];
            long long right = rs[i] - i;
            long long totalways  = left*right;
            long long x = (arr[i]*totalways);
            sum = (sum + x) % M;
        }
        return sum;
    }
};