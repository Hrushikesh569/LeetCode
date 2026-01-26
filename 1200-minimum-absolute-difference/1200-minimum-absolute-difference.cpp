class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mini = 1e9;
        int n = arr.size();
        for(int i = 0 ; i  < n -1 ; i++)
        {
            mini = min(mini,abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>>ans;
        for(int i = 0 ;i < n -1 ;  i++)
        {
            if(mini == abs(arr[i]-arr[i+1]))
            {
                vector<int>v = {arr[i],arr[i+1]};
                ans.push_back(v);
            }
        }
        return ans;
    }
};