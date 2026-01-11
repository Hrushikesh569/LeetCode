class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n  = matrix.size();
        int m = matrix[0].size();
        vector<int>v(m,0);
         int ans = 0 ;
        for(int row = 0 ; row<n ;row++)
        {
            for(int col = 0 ; col< m;col++)
            {
               if(matrix[row][col]=='1')
               {
                v[col]++;
               }
               else
               v[col] = 0 ;
            }
            vector<int>right(m),left(m);
        stack<pair<int,int>>st;
        for(int i = m-1 ; i >=0 ; i--)
        {
            while(!st.empty() && st.top().second>=v[i]) st.pop();
            if(!st.empty())
            {
                right[i] = st.top().first;
            }
            else
            {
                right[i] = m;
            }
            st.push({i,v[i]});
        }
        while(!st.empty()) st.pop();
        for(int i =0 ; i < m ; i++)
        {
            while(!st.empty() && st.top().second>=v[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                left[i]  = st.top().first;
            }
            else
            {
                left[i] = -1;
            }
            st.push({i,v[i]});
        } 
        for(int i =0 ; i < m ; i++)
        {
            ans = max(ans , (right[i]-left[i]-1)*v[i]);
        }
        }
        
        return ans;
    }
};