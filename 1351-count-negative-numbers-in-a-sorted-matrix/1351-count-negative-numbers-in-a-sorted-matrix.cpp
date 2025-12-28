class Solution {
public:
    int fun(vector<int>& arr , int n)
    {
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(arr[mid]>=0)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
           
        }
         return arr.size()-low;

    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0 ;
        for(int i = 0 ;i < grid.size() ; i++)
        {
            count+=fun(grid[i],grid[i].size());
        }
        return count;
    }
};