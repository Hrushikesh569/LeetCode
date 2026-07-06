class Solution {
public:
    bool f(vector<int>&nums , int k , int h)
    {
        int eat = 0 ; 
        for(auto i : nums)
        {
            eat+=((i + k - 1)/k);
            if(eat>h) return 0 ; 
        }
        return 1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = 1e9;
        while(low <= high)
        {
            int mid  = low + (high - low)/2;
            if(f(piles , mid , h ))
            {
                high = mid - 1 ;  
            }
            else
            {
                low = mid + 1;  
            }
        }
        return high + 1 ; 

    }
};