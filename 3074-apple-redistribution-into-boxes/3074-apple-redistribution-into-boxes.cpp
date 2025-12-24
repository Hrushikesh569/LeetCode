class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.rbegin(),capacity.rend());
        int sum = 0 ; 
        for(auto i : apple)sum+=i;
        int cnt = 0; 
        for(int i = 0 ; i < m ; i++)
        {
            if(sum>0)
            {
                sum-=capacity[i];
                cnt++;
            }
        }
        return cnt;
    }
};