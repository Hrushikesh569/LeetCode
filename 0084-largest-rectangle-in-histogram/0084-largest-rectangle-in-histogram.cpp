class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n),right(n);
        stack<pair<int,int>>st;
        for(int i = n - 1; i >=0; i--)
        {
            while(!st.empty() && st.top().first>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                right[i] = st.top().second;
            }
            else
            {
                right[i] = n;
            }
            st.push({heights[i],i});
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n ;i++)
        {
            while(!st.empty() && st.top().first>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i] = st.top().second;
            }
            else
            {
                left[i] = -1;
            }
            st.push({heights[i],i});
        }

        int ans = 0 ; 
        for(int i =0 ;i < n ;i++)
        {
          
            ans = max((right[i]-left[i]-1)*heights[i] , ans);
        }

        return ans;
    }
};