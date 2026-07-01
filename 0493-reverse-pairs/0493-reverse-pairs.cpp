class Solution {
public:
    int merge(vector<int>&v , int low , int mid , int high)
    {
        vector<int>temp;
        int cnt = 0 ; 
        int left = low , right = mid + 1 ; 
        int j = mid+1;
        for(int i = low ; i  <= mid ;i++)
        {
            
            while(j<=high and v[i]*1LL>2*1L*v[j])
            {
                j++;
            }
            cnt+=(j - (mid + 1));
        }
        while(left <= mid and right <= high)
        {
            if(v[left]<=v[right])
            {
                temp.push_back(v[left]);
                left++;        
            }
            else
            {
                temp.push_back(v[right]);
                right++;
            }
        }
        while(left<=mid) temp.push_back(v[left++]);
        while(right<=high)temp.push_back(v[right++]);
        for(int i  = low  ; i < high + 1 ; i++)
        {
            v[i] = temp[i - low];
        }
        return cnt;
    }
    int mergeSort(vector<int>&v , int low , int high)
    {
        if(low>=high)
        return 0 ; 
        int mid = low +(high - low)/2;
        int cnt = 0 ; 
        cnt+=mergeSort(v , low , mid);
        cnt+=mergeSort(v , mid+1 , high);
        cnt+=merge(v , low , mid , high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size()-1);
    }
};