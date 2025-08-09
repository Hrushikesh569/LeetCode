class Solution {
public:
  vector<vector<int>>ans;
    void dfs(vector<int>& arr,vector<int>&temp, int i , int target)
    {
        if(i==arr.size() || target<0)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return ;
        }
       
            temp.push_back(arr[i]);
        dfs(arr,temp,i+1,target-arr[i]);
        temp.pop_back();
        while(i<arr.size()-1 && arr[i]==arr[i+1]) i++;
        dfs(arr,temp,i+1,target);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        ans.clear();
        vector<int>temp;
        sort(arr.begin(),arr.end());
        dfs(arr,temp,0,target);
        return ans;
    }
};